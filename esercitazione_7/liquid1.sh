rm *.dat
cp input.liquid input.in
./NVE_NVT.exe
mv output_epot.dat 7.4/liquido/output_epot.dat
mv output_press.dat 7.4/liquido/output_press.dat
mv output_gf.dat 7.4/liquido/output_gf.dat