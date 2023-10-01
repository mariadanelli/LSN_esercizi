rm *.dat
cp input.solid input.in
./NVE_NVT.exe
mv output_epot.dat 7.4/solido/output_epot.dat
mv output_press.dat 7.4/solido/output_press.dat
mv output_gf.dat 7.4/solido/output_gf.dat