import pandas as pd
from wordcloud import WordCloud

# 1.取出技术关键字所在列数据
data = pd.read_excel("Python/workspace/reptile/Java开发工程师.xlsx")
list1 = data["tag-list"].tolist()
list2 = data["tag-list3"].tolist()
list3 = data["tag-list4"].tolist()
list4 = data["tag-list5"].tolist()
list5 = data["tag-list6"].tolist()
list6 = data["tag-list7"].tolist()
list7 = data["tag-list8"].tolist()

# 2.合并数据
list_all = list1+list2+list3+list4+list5+list6+list7

# 3.数据去重
set_all = set(list_all)
print(set_all)

# 4.转为字符串列表
result = []
for i in set_all:
    result.append(str(i))
# 5.移除不需要的元素
result.remove("nan")
result.remove("后端工程师")
result.remove("中级软件工程师")

# 6.列表转字符串
txt = " ".join(result)


w_c = WordCloud(font_path='/System/Library/Fonts/STHeiti Medium.ttc',
                width=1500,
                height=1000,
                mode='RGBA',
                background_color=None).generate(txt)

w_c.to_file("w_c.png")