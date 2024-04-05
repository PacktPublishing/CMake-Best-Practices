FROM ubuntu:22.04

ARG TZ=Europe/Zurich

# install a few tools for more convenient developing
RUN  apt-get update; \
    LANG="en_US.UTF-8" LANGUAGE="en_US:en" LC_ALL="en_US.UTF-8" DEBIAN_FRONTEND=noninteractive apt-get -y install --fix-missing \
    gdb curl bash-completion vim rpm \
    graphviz python3-pip python-is-python3 doxygen plantuml gcovr \
    clang-tidy cppcheck iwyu zip afl++ clang-format ccache \
    qemu qemu-system-arm gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf libc6-dev-armhf-cross qemu-user \
    # QT runtime prerequisites
    libgl1-mesa-dev libglu1-mesa-dev '^libxcb.*-dev' libx11-xcb-dev libglu1-mesa-dev libxrender-dev libxi-dev \
    libxkbcommon-dev libxkbcommon-x11-dev bash build-essential git wget ninja-build gcovr lcov 

RUN pip install cmake-format pytest pytest-depends cpplint conan

RUN groupadd -r builder 
RUN useradd --create-home --gid builder --groups dialout,plugdev,audio,tty --shell /usr/bin/bash builder

# Download version 3.23 of CMake
RUN wget https://github.com/Kitware/CMake/releases/download/v3.23.2/cmake-3.23.2-linux-x86_64.sh
RUN head cmake-3.23.2-linux-x86_64.sh 
RUN chmod +x ./cmake-3.23.2-linux-x86_64.sh && ./cmake-3.23.2-linux-x86_64.sh --skip-license --prefix=/usr/local 

USER builder

# Download and install vcpkg
RUN cd ~ && curl -OL https://github.com/microsoft/vcpkg/archive/refs/tags/2021.05.12.tar.gz 
RUN mkdir -p ~/.local/opt/vcpkg && mkdir -p ~/.local/bin/ && tar -xvf ~/2021.05.12.tar.gz --strip-components=1 -C ~/.local/opt/vcpkg && rm ~/2021.05.12.tar.gz
RUN ~/.local/opt/vcpkg/bootstrap-vcpkg.sh && ln -s ~/.local/opt/vcpkg/vcpkg ~/.local/bin/vcpkg

# install git shell extension
RUN curl -L https://raw.github.com/git/git/master/contrib/completion/git-prompt.sh > ~/.bash_git && echo "source ~/.bash_git" >> ~/.bashrc
RUN sed -Ei 's/(PS1=.*)(\\\[\\033\[00m\\\]\\\$.*)/\1\\[\\033[01;33m\\]$(__git_ps1)\2/p' ~/.bashrc
