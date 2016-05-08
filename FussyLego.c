int entrada [];
float n[];
float z[];
float p[];
float saida_p[];
float saida_z[];
float saida_n[];
int i=0;
int indP = 0;
int indZ = 0;
int indN = 0;
task main (){
     SetSensorLowspeed (IN_1);
     SetSensorLowspeed (IN_2);
     ArrayInit(entrada, 0, 2);
     ArrayInit(n, 0, 2);
     ArrayInit(z, 0, 2);
     ArrayInit(p, 0, 2);
     ArrayInit(saida_p, 0, 9);
     ArrayInit(saida_z, 0, 9);
     ArrayInit(saida_n, 0, 9);

    while(1){
		indP = 0;
		indZ = 0;
		indN = 0;
		entrada[0] = SensorUS(IN_1);
		entrada[1] = SensorUS(IN_2);
		for(i = 0; i < 2; i ++){
			if(entrada[i] <= 1.75){
				n[i] = 1.00;
				z[i] = 0;
				p[i] = 0;
			}
			if(entrada[i] > 1.75 && entrada[i] <= 3.50){
				n[i] = (1.00 - (((i*1.00) - 1.75)/(3.50 - 1.75)));
				z[i] = (1.00 - (1.00 - (((i * 1.00) - 1.75)/( 3.50 - 1.75 ))));
				p[i] = 0;
			}
			if(entrada[i] > 3.50 && entrada[i] <= 5.25){
				n[i] = 0;
				z[i] = (1.00 - (((i*1.00) - 3.50)/( 5.25 - 3.50)));
				p[i] = (1.00 - (1.00 - (((i * 1.00) - 3.50)/( 5.25 - 3.50 ))));
			}
			if(entrada[i] > 5.25){
				n[i] = 0;
				z[i] = 0;
				p[i] = 1.00;
			}
		}
		if((n[0] >= n[1]) && ( n[1] != 0 )){
			saida_p[indP] = n[1];
			indP ++;
		}else if ((n[0] < n[1]) && ( n[0] != 0 )) {
			saida_p[indP] = n[0];
			indP ++;
		}
		
		if((n[0] >= z[1]) && ( z[1] != 0 )){
			saida_p[indP] = z[1];
			indP ++;
		}else if ((n[0] < z[1]) && ( n[0] != 0 )) {
			saida_p[indP] = n[0];
			indP ++;
		}
		
		if((n[0] >= p[1]) && ( p[1] != 0 )){
			saida_p[indP] = p[1];
			indP ++;
		}else if ((n[0] < p[1]) && ( n[0] != 0 )) {
			saida_p[indP] = n[0];
			indP ++;
		}
		
		if((z[0] >= n[1]) && ( n[1] != 0 )){
			saida_p[indP] = n[1];
			indP ++;
		}else if ((z[0] < n[1]) && ( z[0] != 0 )) {
			saida_p[indP] = z[0];
			indP ++;
		}
		
		if((z[0] >= z[1]) && ( z[1] != 0 )){
			saida_z[indZ] = z[1];
			indZ ++;
		}else if ((z[0] < z[1]) && ( z[0] != 0 )) {
			saida_z[indZ] = z[0];
			indZ ++;
		}
		if((z[0] >= p[1]) && ( p[1] != 0 )){
			saida_z[indZ] = p[1];
			indZ ++;
		}else if ((z[0] < p[1]) && ( z[0] != 0 )) {
			saida_z[indZ] = z[0];
			indZ ++;
		}
		if((p[0] >= n[1]) && ( n[1] != 0 )){
			saida_p[indP] = n[1];
			indP ++;
		}else if ((p[0] < n[1]) && ( p[0] != 0 )) {
			saida_p[indP] = p[0];
			indP ++;
		}
		if((p[0] >= z[1]) && ( z[1] != 0 )){
			saida_z[indZ] = z[1];
			indZ ++;
		}else if ((p[0] < z[1]) && ( p[0] != 0 )) {
			saida_z[indZ] = p[0];
			indZ ++;
		}
		if((p[0] >= p[1]) && ( p[1] != 0 )){
			saida_n[indN] = p[1];
			indN ++;
		}else if ((p[0] < p[1]) && ( p[0] != 0 )) {
			saida_n[indN] = p[0];
			indN ++;
		}
	}

}