(id -nG & id -nu) | tr '
' ' ' | tr ' ' ',' | sed 's/.$//'
