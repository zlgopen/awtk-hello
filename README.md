# awtk-hello

awtk模板工程

## 准备

1.获取awtk并编译

```
git clone https://github.com/zlgopen/awtk.git
cd awtk; scons; cd -
```

2.获取awtk-hello并编译
```
git clone https://github.com/zlgopen/awtk-hello.git
cd awtk-hello; scons
```

## 运行

```
./bin/hello_awtk
```

## 预览UI文件：

```
../awtk/bin/preview_ui res/raw/ui/xxxx.xml
```

> xxxx.xml 换成实际的UI文件。


## 目录说明：

* 1.src 源文件，每个窗口的事件处理放在独立的文件中。

* 2.res/raw/fonts 字体文件。

* 3.res/raw/images 图片。x1下放正常屏幕密度的图片，x2下放高清屏幕密度的图片。

* 4.res/raw/strings 翻译的字符串。

* 5.res/raw/styles 主题配置。default.xml为缺省主题，其它为同名窗口的主题。

* 6.res/raw/ui 界面描述数据。

* 7.res/inc 下为用update\_res.py 生成的数据，其在 src/resource.c中引用。

更新资源后请运行:

```
./update_res.py
```

> 本文以Linux/MacOS为例，Windows可能会微妙差异，请酌情处理。
