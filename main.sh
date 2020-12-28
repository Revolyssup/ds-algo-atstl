imagename="cppimage"
containerName="cppcontainer"
run_script="run.sh"
#to make sure that docker exists.
if test command -v docker > /dev/null 2>&1;then
    echo "Can't find docker on this machine! :("
    exit 1
fi

#build the image
docker build -t $imagename .

# If exit status of build wasn't zero , i.e if build was failed

if [ $? -ne 0 ];then
    echo "Docker build failed!"
    exit 1
fi
#If container does not exist, then create the container.
if [ ! "$(docker ps -aq -f name=$containerName)" ];then
    echo "Creating container..."
    docker create -it -v $(pwd):/app --name "$containerName" $imagename
fi

echo "Starting the container..."
docker start  $containerName

#run the main.sh and carry forward all command line args
docker exec $containerName chmod +x ./run.sh
docker exec -it $containerName ./$run_script "$@"

echo "Stopping..."

docker stop "$containerName"