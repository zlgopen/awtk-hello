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
cd awtk-hello
```

* 生成资源

```
python ./scripts/update_res.py all
```

> 或者通过 designer 生成资源


* 编译PC版本

```
scons
```

* 编译LINUX FB版本

```
scons LINUX_FB=true
```

> 完整编译选项请参考[编译选项](https://github.com/zlgopen/awtk-widget-generator/blob/master/docs/build_options.md)

## 运行

```
./bin/demo
```

## 预览UI文件：

```
../awtk/bin/preview_ui assets/raw/ui/xxxx.xml
```

> xxxx.xml 换成实际的UI文件。


## 目录说明：

* 1. src 源文件，每个窗口的事件处理放在独立的文件中。

* 2. design/default/fonts 字体文件。

* 3. design/default/images 图片。x1下放正常屏幕密度的图片，x2下放高清屏幕密度的图片。

* 4. design/default/strings 翻译的字符串。

* 5. design/default/styles 主题配置。default.xml为缺省主题，其它为同名窗口的主题。

* 6. design/default/ui 界面描述数据。


更新资源后请运行:

```
python ./scripts/update_res.py all
```

> 本文以Linux/MacOS为例，Windows可能会微妙差异，请酌情处理。
