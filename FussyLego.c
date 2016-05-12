#include <stdio.h>
#include <stdlib.h>

int entrada [2];
float n[2];
float z[2];
float p[2];
float saida_p[9];
float saida_z[9];
float saida_n[9];
int i=0;
int indP = 0;
int indZ = 0;
int indN = 0;
float MaxN = 0;
float MaxZ = 0;
float MaxP = 0;
float centroide;
int somatorio1;
int somatorio2;
int somatorio3;
int main (){
     /* SetSensorLowspeed (IN_1);
     SetSensorLowspeed (IN_2);
     ArrayInit(entrada, 0, 2);
     ArrayInit(n, 0, 2);
     ArrayInit(z, 0, 2);
     ArrayInit(p, 0, 2);
     ArrayInit(saida_p, 0, 9);
     ArrayInit(saida_z, 0, 9);
     ArrayInit(saida_n, 0, 9);
*/
    while(1){
		indP = 0;
		indZ = 0;
		indN = 0;
		entrada[0] = 6;//SensorUS(IN_1);
		entrada[1] = 1;//SensorUS(IN_2);
		for(i = 0; i < 2; i ++){
			if(entrada[i] <= 1.50){
				n[i] = 1.00;
				z[i] = 0;
				p[i] = 0;
			}
			if(entrada[i] > 1.50 && entrada[i] <= 3.00){
				n[i] = (1.00 - (((entrada[i]*1.00) - 1.50)/(3.00 - 1.50)));
				z[i] = (1.00 - (1.00 - (((entrada[i] * 1.00) - 1.50)/( 3.00 - 1.50 ))));
				p[i] = 0;
			}
			if(entrada[i] > 3.00 && entrada[i] <= 4.50){
				n[i] = 0;
				z[i] = (1.00 - (((entrada[i]*1.00) - 3.00)/( 4.50 - 3.00)));
				p[i] = (1.00 - (1.00 - (((entrada[i] * 1.00) - 3.00)/( 4.50 - 3.00 ))));
			}
			if(entrada[i] > 4.50){
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
		break;
	}
	for(i = 0; i < indP; i++){
		if(saida_p[i] >= MaxP){
			MaxP = saida_p[i];
		}
	}
	for(i = 0; i < indZ; i++){
		if(saida_z[i] >= MaxZ){
			MaxZ = saida_z[i];
		}
	}
	for(i = 0; i < indN; i++){
		if(saida_n[i] >= MaxN){
			MaxN = saida_n[i];
		}
	}
	for(i = 0; i < 20; i++){
		somatorio1 += i;
	}
	for(i = 20; i < 40; i++){
		somatorio2 += i;
	}

	for(i = 40; i <= 60; i++){
		somatorio3 += i;
	}

	centroide = (somatorio1 * MaxN + somatorio2 * MaxZ + somatorio3 * MaxP)/(MaxN * 20 + MaxZ * 20 + MaxP * 20);
	
	if((entrada[0] < 4.50) || (entrada[1] < 4.50)){
        if(entrada[0] > entrada[1]){
        	printf("Estou rotacionando %.2f graus para o lado do sensor 1 que tem valor %d\n",centroide,entrada[0]);
        	printf("Estou rotacionando -%.2f graus para o lado do sensor 2 que tem valor %d\n",centroide,entrada[1]);
        	printf("Estou rotacionando retrocedendo.\n");
        }else if (entrada[0] < entrada[1]){
        	printf("Estou rotacionando -%.2f graus para o lado do sensor 1 que tem valor %d\n",centroide,entrada[0]);
        	printf("Estou rotacionando %.2f graus para o lado do sensor 2 que tem valor %d\n",centroide,entrada[1]);
        	printf("Estou rotacionando retrocedendo.\n");
        }
    }
    else{
       	printf("Estou andando em linha reta com sensor 1 = %d, sensor 2 = %d\n", entrada[0],entrada[1]);
	}
}
