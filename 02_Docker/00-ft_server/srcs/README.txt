TO BUILD IMAGE:
"docker build . -t myimg"

TO RUN IMAGE
"docker run -itd --rm -p 80:80 -p 443:443 --name=mycont myimg"

TO ENTRY SHELL'S CONTAINER
"docker exec -it mycont /bin/bash"

TO EXIT SHELL'S CONTAINER
"exit"

TO SET WEB AUTOINDEX (ONLY IN THE SHELL'S CONTAINER)
"autoindex on" or "autoindex off"

TO STOP AND CLOSE CONTAINER
"docker stop mycont"
