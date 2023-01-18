


# CMake Best Practices 

<a href="https://www.packtpub.com/product/cmake-best-practices/9781803239729?utm_source=github&utm_medium=repository&utm_campaign="><img src="https://static.packt-cdn.com/products/9781803239729/cover/smaller" alt="CMake Best Practices " height="256px" align="right"></a>

This is the code repository for [CMake Best Practices ](https://www.packtpub.com/product/cmake-best-practices/9781803239729?utm_source=github&utm_medium=repository&utm_campaign=), published by Packt.

**Discover proven techniques for creating and maintaining programming projects with CMake**

## What is this book about?
This book is a collection of some excellent techniques that will help you to make the best use of CMake. It shows you how to integrate various development tools into your CMake workflow and covers field-proven best practices for using CMake effectively even in large, complex settings.

This book covers the following exciting features:

* Get to grips with architecting a well-structured CMake project
* Modularize and reuse CMake code across projects
* Integrate various tools for static analysis, linting, formatting, and documentation into a CMake project
* Get hands-on with performing cross-platform builds
* Get started with crafting a well-defined and portable build environment for your project



If you feel this book is for you, get your [copy](https://www.amazon.com/dp/1803239727) today!

<a href="https://www.packtpub.com/?utm_source=github&utm_medium=banner&utm_campaign=GitHubBanner"><img src="https://raw.githubusercontent.com/PacktPublishing/GitHub/master/GitHub.png" 
alt="https://www.packtpub.com/" border="5" /></a>

## Instructions and Navigations
All of the code is organized into folders. For example, Chapter02.

The code will look like the following:
```
include(GNUInstallDirs)
install(DIRECTORY dir1 DESTINATION ${CMAKE_INSTALL
  _LOCALSTATEDIR} FILES_MATCHING PATTERN "*.x")
install(DIRECTORY dir2 DESTINATION ${CMAKE_INSTALL
  _LOCALSTATEDIR}
  FILES_MATCHING PATTERN "*.hpp" EXCLUDE PATTERN "*")
install(DIRECTORY dir3 DESTINATION ${CMAKE_INSTALL
  _LOCALSTATEDIR} PATTERN "bin" EXCLUDE)
```

**Following is what you need for this book:**
This book is for software engineers and build system maintainers working with C or C++ on a regular basis and trying to use CMake to better effect for their everyday tasks. Basic C++ and general programming knowledge will help you to better understand the examples covered in the book.

With the following software and hardware list you can run all code files present in the book (Chapter 1-15).
### Software and Hardware List
| Chapter | Software required | OS required |
| -------- | ------------------------------------ | ----------------------------------- |
| 1 | CMake 3.21 | Windows, Mac OS X, and Linux (Any) |
| 1 | GCC,Clang or MSVC | Windows, Mac OS X, and Linux (Any) |
| 1 | Git | Windows, Mac OS X, and Linux (Any) |


We also provide a PDF file that has color images of the screenshots/diagrams used in this book. [Click here to download it](https://static.packt-cdn.com/downloads/9781803239729_ColorImages.pdf).

### Related products
* AWS Penetration Testing  [[Packt]](https://www.packtpub.com/product/aws-penetration-testing/9781839216923?utm_source=github&utm_medium=repository&utm_campaign=) [[Amazon]](https://www.amazon.com/dp/1839216921)

* Free eBook - Learn Kali Linux 2019 [[Packt]](https://www.packtpub.com/free-ebook/learn-kali-linux-2019/9781789611809?utm_source=github&utm_medium=repository&utm_campaign=) [[Amazon]](https://www.amazon.com/dp/1789611806)


## Errata


* Page 107 (last line): **make -build ./build cmake -install ./build --prefix /tmp/install-test** _should be_ **make --build ./build cmake --install ./build --prefix /tmp/install-test**



## Get to Know the Author
**Dominik Berner**
is a software engineer, blogger and conference speaker with 20 years of professional software development under his belt. He codes mainly in C++ and has worked on many software projects, from writing bleeding edge software for surgical simulators in a startup, over maintaining large legacy platforms for large corporations in the MedTech industry to creating IoT solutions for companies in between. He beliefs that well designed and maintained build environments are one of the key elements to enable teams to write software efficiently and excel at creating quality software. When he is not writing code, he occasionally writes articles for his blog or speaks at conferences about software development.

**Mustafa Kemal**
is an experienced professional working in performance-critical software development for the telecommunication, defense industries, and open-source software. His expertise is in high-performance and scalable software design, network technologies, DevOps, and software architecture. His interest in computers emerged very early on in his childhood. He learned programming to hack MMORPG games at around the age of 12, and he has been writing software ever since. His favorite programming language is C++, and he enjoys doing framework design & system programming. He is also a strong advocate of CMake; he maintained many codebases and ported many legacy projects to CMake throughout his career.

### Download a free PDF

 <i>If you have already purchased a print or Kindle version of this book, you can get a DRM-free PDF version at no cost.<br>Simply click on the link to claim your free PDF.</i>
<p align="center"> <a href="https://packt.link/free-ebook/9781803239729">https://packt.link/free-ebook/9781803239729 </a> </p>
