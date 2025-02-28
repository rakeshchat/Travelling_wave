set term post eps solid color enhanced "Helvetica" 20
set out 'xrho_cm.eps'

set key r b font "Helvetica, 26"

set xlabel 'x' font "Helvetica, 28"
set ylabel '{/Symbol r}(x)' font "Helvetica, 28"

set mxtics 5
set mytics 2
set xtics () font "Helvetica, 18"
set ytics () font "Helvetica, 18"

#set xrange [ 0 :  ]
#set yrange [ 0.3 : 0.7 ]


#plot 'xrhocm150v1' w lp lt 1 lw 2 pt 3 ps 1.5 ti 'v=1','xrhocm150v0.5' w lp lt 2 lw 2 pt 4 ps 1.5 ti 'v=0.5','xrhocm150v0.25' w lp lt 3 lw 2 pt 6 ps 1.5 ti 'v=0.25','xrhocm150v0.125' w lp lt 4 lw 2 pt 8 ps 1.5 ti 'v=0.125','xrhocm150v0.05' w lp lt 5 lw 2 pt 2 ps 1.5 ti 'v=0.05','xrhocm150v0.025' w lp lt 8 lw 2 pt 10 ps 1.5 ti 'v=0.025'

plot 'xrhocm150v0.001' w lp lt 9 lw 2 pt 12 ps 1.5 ti 'v=0.001',0.5


#,'xrhocm150v0.005' w lp lt 8 lw 2 pt 10 ps 1.5 ti 'v=0.005','xrhocm150v0.0025' w lp lt 8 lw 2 pt 10 ps 1.5 ti 'v=0.0025','xrhocm150v0.001' w lp lt 8 lw 2 pt 10 ps 1.5 ti 'v=0.001'


set term wxt
unset xlabel
unset ylabel
set key default
unset label
set xrange [*:*]
set yrange [*:*]

!evince xrho_cm.eps &
