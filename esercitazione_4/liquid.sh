rm *.dat
cp input.liquid input.in
./NVE_NVT.exe
mv output_tempeq.dat risultati/liquido/output_tempeq.dat
mv output_temp.dat risultati/liquido/output_temp.dat
mv output_press.dat risultati/liquido/output_press.dat
mv output_ekin.dat risultati/liquido/output_ekin.dat
mv output_epot.dat risultati/liquido/output_epot.dat
mv output_etot.dat risultati/liquido/output_etot.dat