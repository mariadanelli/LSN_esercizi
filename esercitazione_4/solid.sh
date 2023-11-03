rm *.dat
cp input.solid input.in
./NVE_NVT.exe
mv output_tempeq.dat risultati/solido/output_tempeq.dat
mv output_temp.dat risultati/solido/output_temp.dat
mv output_press.dat risultati/solido/output_press.dat
mv output_ekin.dat risultati/solido/output_ekin.dat
mv output_epot.dat risultati/solido/output_epot.dat
mv output_etot.dat risultati/solido/output_etot.dat