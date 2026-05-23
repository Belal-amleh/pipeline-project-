import re
import matplotlib.pyplot as plt
import sys, os
base = sys.argv[1] if len(sys.argv) > 1 else os.getcwd()
os.chdir(base)


# --------- 1) Reading helper functions ---------

def read_int_matrix(path):
    rows = []
    with open(path, "r", encoding="utf-8") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                row = list(map(int, line.split()))
            except ValueError:
                # skip non-integer lines safely
                continue
            rows.append(row)
    # pad to rectangular shape with -2 (empty)
    if rows:
        max_len = max(len(r) for r in rows)
        for r in rows:
            if len(r) < max_len:
                r += [-2] * (max_len - len(r))
    return rows

def read_order(path="order.txt", expected_rows=None):
    try:
        with open(path, "r", encoding="utf-8") as f:
            text = f.read().strip()
    except FileNotFoundError:
        text = ""
    if not text:
        # fall back to sequential labels if file missing/empty
        return list(range(expected_rows or 0))
    try:
        order = list(map(int, text.split()))
    except ValueError:
        order = list(range(expected_rows or 0))
    # if length mismatches, fix to expected length
    if expected_rows is not None and len(order) != expected_rows:
        order = order[:expected_rows] + list(range(len(order), expected_rows))
    return order

def read_speedup(path):
    """Return (a, b, ratio). Accepts 1 or 2 numbers in the file."""
    try:
        txt = open(path, "r", encoding="utf-8").read().strip()
    except FileNotFoundError:
        return 0.0, 0.0, 0.0
    nums = re.findall(r"[-+]?(?:\d+(?:\.\d*)?|\.\d+)", txt)
    if not nums:
        return 0.0, 0.0, 0.0
    a = float(nums[0])
    b = float(nums[1]) if len(nums) > 1 else 0.0
    ratio = (a / b) if b != 0 else (a if len(nums) == 1 else float("inf"))
    return a, b, ratio

# --------- 2) Stage name mapping ---------

stage_names = {
    -2: "",        # empty
    -1: "STALL",
     0: "IF",
     1: "ID",
     2: "EX",
     3: "MEM",
     4: "WB",
}
def int_table_to_str(table):
    return [[stage_names.get(x, "?") for x in row] for row in table]

# --------- 3) Plotting pipeline tables ---------

def plot_pipeline_table(str_table, row_labels, title, speed_info=None):
    n_rows = len(str_table)
    if n_rows == 0:
        return
    n_cols = len(str_table[0])
    col_labels = [f"C{j+1}" for j in range(n_cols)]
    # ensure label count matches
    if len(row_labels) != n_rows:
        row_labels = [f"I{i+1}" for i in range(n_rows)]

    fig, ax = plt.subplots(figsize=(n_cols * 0.7, n_rows * 0.6 + 1.6))
    ax.axis("off")
    tbl = ax.table(
        cellText=str_table,
        rowLabels=row_labels,
        colLabels=col_labels,
        loc="center"
    )
    tbl.auto_set_font_size(False)
    tbl.set_fontsize(9)
    tbl.scale(1, 1.4)
    ax.set_title(title, pad=20)

    # write speedup under the table
    if speed_info is not None:
        a, b, r = speed_info
        if b != 0:
            text = f"Speedup = {a:.0f} / {b:.0f} = {r:.3f}"
        else:
            text = f"Speedup = {a:.3f}" if a and r == a else "Speedup: N/A"
        ax.text(
            0.5, -0.12, text,
            transform=ax.transAxes,
            ha="center", va="top"
        )

    fig.tight_layout()
    plt.show()

# --------- 4) Main ---------

if __name__ == "__main__":
    # 1) Read data
    stall_tab = read_int_matrix("StallForwarding.txt")
    reord_tab = read_int_matrix("reorderingForwarding.txt")

    # 2) Labels
    stall_labels = [f"I{i+1}" for i in range(len(stall_tab))]
    order = read_order("order.txt", expected_rows=len(reord_tab))  # robust
    reord_labels = [f"I{idx+1}" for idx in order]

    # 3) Speedups
    s1 = read_speedup("speedUp1.txt")
    s2 = read_speedup("speedUp2.txt")

   
    # 5) Plots
    plot_pipeline_table(int_table_to_str(stall_tab), stall_labels,
                        "Stall + Forwarding", speed_info=s1)
    plot_pipeline_table(int_table_to_str(reord_tab), reord_labels,
                        "Forwarding + Reordering", speed_info=s2)
