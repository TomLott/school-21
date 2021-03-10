docker build -t ft_server .
docker run ft_server --it p 80:80 p 443:443
