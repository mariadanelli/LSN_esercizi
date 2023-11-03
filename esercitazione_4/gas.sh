rm *.dat
cp input.gas input.in
./NVE_NVT.exe
mv output_tempeq.dat risultati/gas/output_tempeq.dat
mv output_temp.dat risultati/gas/output_temp.dat
mv output_press.dat risultati/gas/output_press.dat
mv output_ekin.dat risultati/gas/output_ekin.dat
mv output_epot.dat risultati/gas/output_epot.dat
mv output_etot.dat risultati/gas/output_etot.dat