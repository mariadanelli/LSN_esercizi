rm *.dat
cp input.liquid input.in
./NVE_NVT.exe
mv output_tempeq.dat 'Equilibrio temperatura'/liquido/output_tempeq.dat
mv output_temp.dat 'Equilibrio temperatura'/liquido/output_temp.dat
mv output_press.dat 'Equilibrio temperatura'/liquido/output_press.dat
mv output_ekin.dat 'Equilibrio temperatura'/liquido/output_ekin.dat
mv output_epot.dat 'Equilibrio temperatura'/liquido/output_epot.dat
mv output_etot.dat 'Equilibrio temperatura'/liquido/output_etot.dat