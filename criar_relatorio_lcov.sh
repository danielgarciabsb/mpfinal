~/Desktop/lcov-1.12/bin/lcov -t "Teste do Simulador" -o lcov_projeto_mp.info -c -d .
genhtml lcov_projeto_mp.info --output-directory relatorio_lcov
rm lcov_projeto_mp.info
