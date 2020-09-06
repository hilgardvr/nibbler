#bin/bash

#for macos run (assuming virtual-box and docker-machine are already installed): docker-machine create --driver virtualbox nibbler-machine
#for macos to export docker-machine env run: eval "$(docker-machine env nibbler-machine)"

docker build -t nibbler .
docker run -it nibbler /bin/bash