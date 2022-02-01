FROM conanio/gcc11:1.44.1

RUN pip install cmake-format

# switch to root
USER root

# install a few tools for more convenient developing
RUN  apt-get update; \
    apt-get -y install --fix-missing \
    gdb curl bash-completion vim rpm \
    graphviz python3-pytest doxygen plantuml gcovr \
    clang-tidy cppcheck iwyu zip

RUN pip3 install cpplint

# Download version 3.21 from CMake
RUN curl -OL https://github.com/Kitware/CMake/releases/download/v3.21.2/cmake-3.21.2-linux-x86_64.sh

RUN chmod +x ./cmake-3.21.2-linux-x86_64.sh && ./cmake-3.21.2-linux-x86_64.sh --skip-license --prefix=/opt/pyenv/versions/3.7.5/ && rm ./cmake-3.21.2-linux-x86_64.sh

USER conan

# Download and install vcpkg
RUN curl -OL https://github.com/microsoft/vcpkg/archive/refs/tags/2021.05.12.tar.gz 
RUN mkdir -p ~/.local/opt/vcpkg && mkdir -p ~/.local/bin/ && tar -xvf 2021.05.12.tar.gz --strip-components=1 -C ~/.local/opt/vcpkg && rm 2021.05.12.tar.gz
RUN ~/.local/opt/vcpkg/bootstrap-vcpkg.sh && ln -s ~/.local/opt/vcpkg/vcpkg ~/.local/bin/vcpkg

#install git shell extension
RUN curl -L https://raw.github.com/git/git/master/contrib/completion/git-prompt.sh > ~/.bash_git && echo "source ~/.bash_git" >> ~/.bashrc
RUN sed -Ei 's/(PS1=.*)(\\\[\\033\[00m\\\]\\\$.*)/\1\\[\\033[01;33m\\]$(__git_ps1)\2/p' ~/.bashrc
