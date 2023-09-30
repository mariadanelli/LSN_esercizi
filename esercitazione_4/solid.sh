rm *.dat
cp input.solid input.in
./NVE_NVT.exe
mv output_tempeq.dat 'Equilibrio temperatura'/solido/output_tempeq.dat
mv output_temp.dat 'Equilibrio temperatura'/solido/output_temp.dat
mv output_press.dat 'Equilibrio temperatura'/solido/output_press.dat
mv output_ekin.dat 'Equilibrio temperatura'/solido/output_ekin.dat
mv output_epot.dat 'Equilibrio temperatura'/solido/output_epot.dat
mv output_etot.dat 'Equilibrio temperatura'/solido/output_etot.dat