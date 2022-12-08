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
list1 = data["工作地点"].tolist()

# 1、按区划分
# 2、异常处理
# 3、字符长度
# 4、字符截取


list2 = []
for i in list1:
    try:

        s = str(i).split("·")[0]
        b = str(i).split("·")[1]
        list2.append(s+b)
    except:
        s = str(i).split("·")[0]
        list2.append(s)

    

list3 = Counter(list2)


c = (
    Pie()
    .add("", [list(z) for z in zip(list3.keys(), list3.values())])
    #.set_global_opts(title_opts=opts.TitleOpts(title=""))
    .set_series_opts(label_opts=opts.LabelOpts(formatter="{b}: {c}"))
    .render("pie_base.html")
)
