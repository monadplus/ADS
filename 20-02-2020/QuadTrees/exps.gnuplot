#
# use with gnuplot
#

set terminal jpeg

#
# Axis ranges
# set xrange[0:1]

# Relaxed Kd trees
# K 3

# w yerrorb

# set output "rlx-ssu-25M-500.jpeg"
# set title 'q = (x, y, *), n = 25000, M = 500'
# set xlabel 'y'
# plot "rlx-ssu-25M-500-X0.res" u 5:($6/(($3)**0.387))  t 'x = 0' lt -1 lc rgb "green" w l,\
#      "rlx-ssu-25M-500-X0.res" u 5: (4.5959*(sqrt($5*(1-$5)))**0.387) not lc rgb "green" w l,\
#      "rlx-ssu-25M-500-X01.res" u 5:($6/(($3)**0.457))  t 'x = 0.1' lt -1 lc rgb "blue" w l,\
#      "rlx-ssu-25M-500-X01.res" u 5: (6.92939*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.457) not lc rgb "blue"  w l,\
#      "rlx-ssu-25M-500-X25.res" u 5:($6/(($3)**0.457427108)) t 'x = 0.25' lt -1 lc rgb "red" w l,\
#      "rlx-ssu-25M-500-X25.res" u 5: (6.92939*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.457) not lc rgb "red" w l,\
#      "rlx-ssu-25M-500-X50.res" u 5:($6/(($3)**0.457427108)) t 'x = 0.50' lt -1 lc rgb "purple" w l,\
#      "rlx-ssu-25M-500-X50.res" u 5: (6.92939*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.457) not lc rgb "purple"  w l;
# 
# set output "rlx-ssu-25M-500-err.jpeg"
# set title 'q = (x, y, *), n = 25000, M = 500'
# set xlabel 'y'
# plot "rlx-ssu-25M-500-X0.res" u 5:(sqrt($7)/$6) t 'x = 0' lt -1 lc rgb "green" w l,\
#      "rlx-ssu-25M-500-X01.res" u 5:(sqrt($7)/$6)  t 'x = 0.1' lt -1 lc rgb "blue" w l,\
#      "rlx-ssu-25M-500-X25.res" u 5:(sqrt($7)/$6) title 'x = 0.25' lt -1 lc rgb "red" w l,\
#      "rlx-ssu-25M-500-X50.res" u 5:(sqrt($7)/$6) title 'x = 0.50' lt -1 lc rgb "purple" w l;
#      
# set output "rlx-ssu-var-n.jpeg"
# set title 'q = (0.25, y, *), M = 500'
# set xlabel 'y'
# plot "rlx-ssu-1M-500-X25.res" u 5:($6/(($3)**0.457)) t 'n = 1000' lt -1 lc rgb "green" w l,\
#      "rlx-ssu-5M-500-X25.res" u 5:($6/(($3)**0.457)) t 'n = 5000' lt -1 lc rgb "blue" w l,\
#      "rlx-ssu-25M-500-X25.res" u 5:($6/(($3)**0.457)) t 'n = 25000' lt -1 lc rgb "red" w l,\
#      "rlx-ssu-25M-500-X25.res" u 5: (6.92939*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.457) not lt -1  w l;
# 
#      
# set output "std-K3-S2-25M-500.jpeg"
# set title 'n = 25000, M = 500'
# set xlabel 'y'
# plot "std-uss-25M-500-X25.res" u 5:($6/(($3)**0.39)) t 'q = (*, 0.25, y)' lt -1 lc rgb "blue" w l,\
#      "std-uss-25M-500-X25.res" u 5: (9.1612*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.39) not lc rgb "blue" w l,\
#      "std-sus-25M-500-X25.res" u 5:($6/(($3)**0.39)) t 'q = (0.25, *, y)' lt -1 lc rgb "red" w l,\
#      "std-sus-25M-500-X25.res" u 5: (7.6485*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.39) not lc rgb "red" w l,\
#      "std-ssu-25M-500-X25.res" u 5:($6/(($3)**0.39)) t 'q = (0.25, y, *)' lt -1 lc rgb "green" w l,\
#      "std-ssu-25M-500-X25.res" u 5: (6.3915*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.39) not lc rgb "green" w l;
#      
# 
# set output "std-K3-S2-25M-500-err.jpeg"
# set title 'n = 25000, M = 500'
# set xlabel 'y'
# plot "std-uss-25M-500-X25.res" u 5:(sqrt($7)/$6) t 'q = (*, 0.25, y)' lt -1 lc rgb "blue" w l,\
#      "std-sus-25M-500-X25.res" u 5:(sqrt($7)/$6) t 'q = (0.25, *, y)' lt -1 lc rgb "red" w l,\
#      "std-ssu-25M-500-X25.res" u 5:(sqrt($7)/$6) t 'q = (0.25, y, *)' lt -1 lc rgb "green" w l;
#  

# set output "sqsh-ssu-25M-5M.jpeg"
# set title 'q = (x, y, *), n = 25000, M = 5000'
# set xlabel 'y'
# plot "sqsh-ssu-25M-5M-X0.res" u 5:($6/($3)**(1-($2/$1)))  t 'x = 0' lt -1 lc rgb "green" w l,\
#      "sqsh-ssu-25M-5M-X25.res" u 5:($6/($3)**(1-($2/$1))) t 'x = 0.25' lt -1 lc rgb "red" w l,\
#      "sqsh-ssu-25M-5M-X50.res" u 5:($6/($3)**(1-($2/$1))) t 'x = 0.50' lt -1 lc rgb "blue" w l;
     
# set output "sqsh-K3-nvar-0uu.jpeg"
# set title 'q = (0, *, *)'
# set xlabel 'y'
# plot "sqsh-nvar-0uu.res" u 3:($6/($3)**(1-($2/$1)))  t '0uu' w l;
     
     
set output "sqsh-K4-nvar-logscale.jpeg"
set xlabel 'log n'
set logscale
plot "sqsh-nvar-000u-100M.res" u 3:7  t '000u' lt -1 lc rgb "green" w l,\
     "sqsh-nvar-00su-100M.res" u 3:7 t '00su' lt -1 lc rgb "red" w l,\
     "sqsh-nvar-0ssu-100M.res" u 3:7 t '0ssu' lt -1 lc rgb "orange" w l,\
     "sqsh-nvar-sssu-100M.res" u 3:7 t 'sssu' lt -1 lc rgb "blue" w l,\
     "sqsh-nvar-sssu-100M.res" u 3:(($3)**(0.25)) t 'n^(1/4)' lt 2 lc \
     rgb "black" w l;

# set output "sqsh-ssu-25M-5M-err.jpeg"
# set title 'q = (x, y, *), n = 25000, M = 5000'
# set xlabel 'y'
# plot "sqsh-ssu-25M-5M-X0.res" u 5:(sqrt($7)/$6)  t 'x = 0' lt -1 lc rgb "green" w l,\
#      "sqsh-ssu-25M-5M-X25.res" u 5:(sqrt($7)/$6) title 'x = 0.25' lt -1 lc rgb "red" w l,\
#      "sqsh-ssu-25M-5M-X50.res" u 5:(sqrt($7)/$6) title 'x = 0.50' lt -1 lc rgb "blue" w l;
#      

#  
# Proceso de datos para estudiar el segundo término
# 
#  


# set output "rlx-ssu-25M-500-2nTlog.jpeg"
# set title 'q = (x, y, *), n = 25000, M = 500'
# set xlabel 'y'
# plot "rlx-ssu-25M-500-X0.res" u 5:(($6/(($3)**0.387)) -  (4.5959*(sqrt($5*(1-$5)))**0.387))t 'x = 0' lt -1 lc rgb "green" w l,\
#      "rlx-ssu-25M-500-X01.res" u 5:(($6/(($3)**0.457)) -  (6.92939*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.457)) t 'x = 0.1' lt -1 lc rgb "blue" w l,\
#      "rlx-ssu-25M-500-X25.res" u 5:(($6/(($3)**0.457427108)) - (6.92939*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.457)) t 'x = 0.25' lt -1 lc rgb "red" w l,\
#      "rlx-ssu-25M-500-X50.res" u 5:(($6/(($3)**0.457427108))- (6.92939*(sqrt(($5)*(1-$5)*($4)*(1-$4)))**0.457)) t 'x = 0.50' lt -1 lc rgb "purple" w l;
     
     
     
     
# set output "rlx-ssu-error-loglog.jpeg"
# set title 'q = (x, y, *), M = 500'
# set xlabel 'n'
# plot "error1.exp" u 3:(($6) -  (6.92939*((sqrt(($5)*(1-$5)*($4)*(1-$4)))*($3))**0.457)) t 'x = 0.5, y = 0.5' lt -1 lc rgb "blue" w l,\
#      "error2.exp" u 3:(($6) - (6.92939*((sqrt(($5)*(1-$5)*($4)*(1-$4)))*($3))**0.457)) t 'x = 0.5, y = 0.1' lt -1 lc rgb "red" w l,\
#      "error3.exp" u 3:(($6)-  (6.92939*((sqrt(($5)*(1-$5)*($4)*(1-$4)))*($3))**0.457)) t 'x = 0.1, y = 0.1' lt -1 lc rgb "purple" w l;
