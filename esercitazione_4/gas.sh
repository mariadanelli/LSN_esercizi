rm *.dat
cp input.gas input.in
./NVE_NVT.exe
mv output_tempeq.dat 'Equilibrio temperatura'/gas/output_tempeq.dat
mv output_temp.dat 'Equilibrio temperatura'/gas/output_temp.dat
mv output_press.dat 'Equilibrio temperatura'/gas/output_press.dat
mv output_ekin.dat 'Equilibrio temperatura'/gas/output_ekin.dat
mv output_epot.dat 'Equilibrio temperatura'/gas/output_epot.dat
mv output_etot.dat 'Equilibrio temperatura'/gas/output_etot.dat