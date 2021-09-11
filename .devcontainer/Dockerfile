FROM conanio/gcc11:1.39.0

# switch to root
USER root

# install a few tools for more convenient developing
RUN  apt-get update; \
    apt-get -y install --fix-missing \
    gdb curl bash-completion vim 

USER conan

RUN pip install cmake-format

#install git shell extension
RUN curl -L https://raw.github.com/git/git/master/contrib/completion/git-prompt.sh > ~/.bash_git && echo "source ~/.bash_git" >> ~/.bashrc
RUN sed -Ei 's/(PS1=.*)(\\\[\\033\[00m\\\]\\\$.*)/\1\\[\\033[01;33m\\]$(__git_ps1)\2/p' ~/.bashrc
