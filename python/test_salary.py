#!/opt/anaconda3/bin/python
from pyecharts.globals import CurrentConfig, NotebookType
CurrentConfig.NOTEBOOK_TYPE = NotebookType.JUPYTER_LAB
#引入pands
import pandas as pd
from collections import Counter
from pyecharts import options as opts
from pyecharts.charts import Page,Pie,Bar
from pyecharts.globals import ThemeType
from pyecharts.charts import Pie
from pyecharts.faker import Faker


file_url = "reptile/Java开发工程师.xlsx"
data = pd.read_excel(file_url)
list1 = data["薪资待遇"].tolist()

# print(list1)

list2 = []
for i in list1:
    s = str(i).split("·")[0]
    list2.append(s)

list3 = Counter(list2)

print(list3)
c = (
Pie()
.add("", [list(z) for z in zip(list3.keys(), list3.values())],
label_opts=opts.LabelOpts(is_show=False))
.set_global_opts(title_opts=opts.TitleOpts(title="工资信息"))
.set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {c}"))
)
c.render_notebook()



# c = (
#     Pie()
#     .add("", [list(z) for z in zip(list3.keys(), list3.values())])
#     #.set_global_opts(title_opts=opts.TitleOpts(title=""))
#     .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {c}"))
#     .render("pie_base.html")
# )
