# minimal docker example

This example illustrate how to execute cmake inside a [docker](http://docker.io/) container. 
To build the docker container use 

```bash
docker build . -t builder_minimal --rm
```

This will build a local docker image called 'builder_minimal'. The `--rm` flag tells docker to delete any intermediate containers used to create the final image. This conservers disk space on your host. 

To build the example inside docker run:
```bash

docker run --user $(id -u):$(id -g) --rm -v $(pwd):/workspace builder_minimal cmake -S /workspace -B /workspace/build 
docker run --user $(id -u):$(id -g) --rm -v $(pwd):/workspace builder_minimal cmake --build /workspace/build 

```

the `--user $(id -u):$(id -g)` flag will tell docker to run as the current user. The user-ID and group id are retrieved using the `id` command from bash. If running on windows this might be ignored. 
The `--rm` flag tells docker to discard the container after use. 
the `-v` flag tells docker to mount the curent working director into the container to the path `/workspace`
After the flags the cmanke commands to be executed inside the docker container are passed. 