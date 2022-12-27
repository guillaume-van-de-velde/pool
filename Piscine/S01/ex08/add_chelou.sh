echo $FT_NBR1 + $FT_NBR2 | tr "'"'\\"?!mrdoc' '0123401234'| xargs -I{} echo 'obase=13;ibase=5;'{} | bc | tr "0123456789ABC" "gtaio luSnemf"
