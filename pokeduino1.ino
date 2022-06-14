#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Wire.h>

//-------Configuracion Wire

const short esclavo = 1;
const short maxByte = 15;
volatile char nombre [maxByte];

//---------Funciones Wire



//--------Teclado

 const byte filas = 4;
  const byte columnas = 4;

  char teclado [filas][columnas] = 
  {
    {'1','2','3','A'},
    {'4','5','6','B'},
    {'7','8','9','C'},
    {'*','0','#','D'},
  };
  byte pinsFilas [filas] = {9,8,7,6};
  byte pinsColumnas [columnas] = {5,4,3,2};
  Keypad pad = Keypad (makeKeymap(teclado),pinsFilas, pinsColumnas,filas,columnas);

//-----------------LCD

LiquidCrystal lcd(12,11,A0,A1,A2,A3);


//------------Funciones

String elegirPokemon (char pokemon)
{
  char confirmar;
  LiquidCrystal lcd2(12,11,A0,A1,A2,A3);  
  String elegido;
  bool seleccionado = false;
  while(!seleccionado) {
    if(pokemon)
  	{
    	switch (pokemon)
    	{
    	  case '1':
    		elegido = "Serperior";
    		break;
     	 case '2':
   		 	elegido = "Blastoize";
    		break;
    	  case '3':
   		 	elegido = "Arcanine";
  	 	 	break;
  	    case '4':
          elegido = "Goodra";
          break;
        case '5':
          elegido = "Sylveon";
          break;
        case '6':
          elegido = "Melmetal";
          break;
        }  
      lcd2.clear();
      lcd2.print("El Pokemon Seleccionado es: ");
      delay(1000);
      lcd2.clear();
      lcd2.print(elegido);
      delay(1000);
      lcd2.clear();
      lcd2.print("Es correcto?");
      confirmar = pad.waitForKey();
      switch (confirmar)
      {
        case '#':
        	lcd2.clear();
        	lcd2.print("El pokemon elegido es:");
        	delay(1000);
        	lcd2.clear();
        	lcd2.print(elegido);
        	delay(1000);
    		seleccionado = true;
      		break;
      }
  	}
    
    
  }
  return elegido;
}

//---------------------Funcion de Ataque Esp

LiquidCrystal lcd3(12,11,A0,A1,A2,A3);

int atqEsp (String pokemon1,String pokemon2, int atqEsp){
  String atacante = pokemon1;
  String defensor = pokemon2;
  int atq = atqEsp;

  lcd3.clear();
  if(atacante == "Serperior")
  {
    lcd3.clear();
    lcd3.print("Serperior uso ataque Planta...");
    delay(1000);

    if(defensor = ("Arcanine" || "Melmetal" || "Goodra"))
    {
      lcd3.print("El ataque fue poco efectivo.");
      delay(2000);
      atq = atq * 0.5;
    }
    else if (defensor == "Blastoize")
    {
      lcd3.print("El ataque fue super efectivo.");
      delay(2000);
      atq = atq + atq / 2;
    }

  }else if(atacante == "Blastoize")
  {
    lcd3.clear();
    lcd3.print("Blastoise uso ataque Agua...");
    delay(1000);
    if(defensor = "Arcanine"){
      lcd3.print("El ataque fue muy efectivo.");
      delay(2000);
      atq = atq * 1.5;
    }else if (defensor == "Serperior"){
      lcd3.print("El ataque fue poco efectivo.");
      delay(2000);
      atq = atq * 0.5;
    }
  }else if(atacante == "Arcanine"){
    lcd3.clear();
    lcd3.print("Arcanine uso ataque Fuego...");
    delay(1000);
    if(defensor = "Blastoize"){
      lcd3.print("El ataque fue poco efectivo.");
      delay(2000);
      atq = atq / 2;
    }else if (defensor = ("Serperior" || "Melmetal")){
      lcd3.print("El ataque fue muy efectivo.");
      delay(2000);
      atq = atq * 1.5;
    }
  }else if (atacante == "Goodra"){
    lcd3.clear();
    lcd3.print("Goodra uso ataque Dragon...");
    if(defensor = "Goodra"){
      lcd3.print("El ataque es muy efectivo.");
      delay(2000);
      atq = atq * 1.5;
    }else if (defensor == "Sylveon" ||  "Melmetal"){
      lcd3.print("El ataque fue poco efectivo.");
      delay(2000);
      atq = atq / 2;
    }
  }else if (atacante == "Sylveon"){
    lcd3.clear();
    lcd3.print("Sylveon uso ataque Hada...");
    if(defensor == "Goodra"){
      lcd3.print("El ataque es muy efectivo.");
      delay(2000);
      atq = atq * 1.5;
    }else if (defensor == "Melmetal"){
      lcd3.print("El ataque fue poco efectivo.");
      delay(2000);
      atq = atq / 2;
    }
 }else if (atacante == "Melmetal"){
   lcd3.clear();
   lcd3.print("Melmetal uso ataque Metal...");
   if(defensor == "Sylveon"){
     lcd3.print("El ataque es muy efectivo.");
     delay(2000);
     atq = atq * 1.5;
   }else if (defensor == "Blastoize"){
     lcd3.print("El ataque fue poco efectivo.");
     delay(2000);
     atq = atq / 2;
    }
  }
       return atq;
}
       
//-------------- Menu Pelea

LiquidCrystal lcd4(12,11,A0,A1,A2,A3);

void pelea (String pokemon1, String pokemon2, int HPokemon1, int HPPokemon2){
  bool menu = false;
  String atacante = pokemon1;
  String defensor = pokemon2;
  int HP1 = CantHP(atacante);
  int HP2 = CantHP(defensor);
  int neutro = CantAtkN(atacante);
  int especial = CantAtkE(atacante);
  while(!menu)
  {
    lcd4.clear();
    lcd4.setCursor(0,0);
    lcd4.print("1.Ataque,2.Cambiar");
    lcd4.setCursor(0,1);
    lcd4.print("3.Ver info");
    char opc = pad.waitForKey();
    if(opc = 1){
      lcd4.clear();
      lcd4.setCursor(0,0);
      lcd4.print("1.Neutro");
      lcd4.setCursor(0,1);
      lcd4.print("2.Especial");
      opc = pad.waitForKey();
      if(opc = 1){
        lcd4.clear();
        lcd4.print(atacante);
        lcd4.print("ataque Neutro.");
        HP2 = HP2 - neutro;
      }
      else if(opc = 2){
        int esp = atqEsp(atacante, defensor, especial);
        HP2 = HP2 - esp;
      }
    
    }
  
    //else if(opc = 2){
      
    //}
    else if(opc = 3){
      lcd4.clear();
      lcd4.print(atacante);
      lcd4.print(" ");
      lcd4.print(HP1);
      delay(100);
      lcd4.setCursor(0,1);
      lcd4.print(defensor);
      lcd4.print(" ");
      lcd4.print(HP2);
      delay(100);
      
    }
  }
}

// ----- Equipo en Pelea

int PokemonEnPelea(String pokemon, int HP, int atk){
  String Peleando = pokemon;
  int ataque = atk;
  int hp = HP;
  int HPFinal = hp - atk;
  return HPFinal;
}

void PokemonDescansando(String pokemon, String Poke1, String Poke2, String Poke3, int HP, int ataque){
  String poke1 = Poke1;
  String poke2 = Poke2;
  String poke3 = Poke3;
  String enPelea = pokemon;
  int HP1 = CantHP(Poke1);
  int HP2 = CantHP(Poke2);
  int HP3 = CantHP(Poke3);
  int restaHP1 = HP1;
  int restaHP2 = HP2;
  int restaHP3 = HP3;
  
  if(enPelea == poke1){
     restaHP1 = restaHP1 - ataque;
  }else{
    if(restaHP1 <=0){
      restaHP1 = 0;
    }else{
      restaHP1 = restaHP1 + 10;
      if(restaHP1 > HP1){
        restaHP1 = HP1;
      }
      
    }
  }
  if(enPelea == poke2){
     restaHP2 = restaHP2 - ataque;
  }else{
    if(restaHP2 <=0){
      restaHP2 = 0;
    }else{
      restaHP2 = restaHP2 + 10;
      if(restaHP2 > HP2){
        restaHP2 = HP2;
      }
      
    }
    
  }
  if(enPelea == poke3){
     restaHP3 = restaHP3 - ataque;
  }else{
    if(restaHP3 <=0){
      restaHP3 = 0;
    }else{
      restaHP3 = restaHP3 + 10;
      if(restaHP3 > HP3){
        restaHP3 = HP3;
      }
      
      
    }
  }
  
}

// --- HP

int CantHP (String poke){
  String pokemon = poke;
  int HP;
  if(pokemon == "Serperior"){
    HP = 115;
  }
  else if(pokemon == "Blastoize"){
    HP = 105;
  }
  else if(pokemon == "Arcanine"){
    HP = 80;
  }
  else if(pokemon == "Goodra"){
    HP = 95;
  }
  else if(pokemon == "Sylveon"){
    HP = 110;
  }
  else
  {
    HP = 100;
  }
  return HP;
}

int CantAtkN (String pokemon){
  String poke = pokemon;
  int neutro;
  if(pokemon == "Serperior" || "Melmetal"){
    neutro = 10;
  }
  if(pokemon == "Blastoize" || "Sylveon"){
    neutro = 12;
  }
  if(pokemon == "Arcanine"){
    neutro = 18;
  }
  if(pokemon == "Goodra"){
    neutro = 14;
  }
  return neutro;
}


int CantAtkE (String pokemon){
  String poke = pokemon;
  int esp;
  if(pokemon == "Serperior" || "Blastoize" || "Sylveon" ){
    esp = 24;
  }
  if(pokemon == "Arcanine"){
    esp = 30;
  }
  if(pokemon == "Goodra"){
    esp = 26;
  }
  if(pokemon == "Melmetal")
  {
    esp = 28;
  }
  return esp;
}

  // ---Cambio Pokemon



String pokemon (String poke){
  String pokemon = poke;
  return pokemon;
}

int HP (String poke){
  int hp = CantHP(poke);
  return hp;
}

  // ------ Equipo Pokemon

void EquipoPokemon(String poke1, String poke2, String poke3){
  
  LiquidCrystal lcd(12,11,A0,A1,A2,A3);
  String pokemon1 = poke1;
  String pokemon2 = poke2;
  String pokemon3 = poke3;
  int HP1 = CantHP(poke1);
  int HP2 = CantHP(poke2);
  int HP3 = CantHP(poke3);
  int atkN1 = CantAtkN(poke1);
  int atkN2 = CantAtkN(poke2);
  int atkN3 = CantAtkN(poke3);
  int atkE1 = CantAtkE(poke1);
  int atkE2 = CantAtkE(poke2);
  int atkE3 = CantAtkE(poke3);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(pokemon1);
  lcd.setCursor(9,0);
  lcd.print(" HP:");
  lcd.print(HP1);
  delay(1000);
  lcd.clear();
  lcd.print("Atk.Neutro: ");
  lcd.print(atkN1);
  delay(1000);
  lcd.clear();
  lcd.print("Atk.Especial: ");
  lcd.print(atkE1);
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(pokemon2);
  lcd.print(" ");
  lcd.print(HP2);
  delay(1000);
  lcd.clear();
  lcd.print("Atk.Neutro: ");
  lcd.print(atkN2);
  delay(1000);
  lcd.clear();
  lcd.print("Atk.Especial: ");
  lcd.print(atkE2);
  delay(1000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(pokemon3);
  lcd.print(" ");
  lcd.print(HP3);
  lcd.clear();
  lcd.print("Atk.Neutro: ");
 lcd.print(atkN3);
  delay(1000);
  lcd.clear();
  lcd.print("Atk.Especial: ");
  lcd.print(atkE3);
  delay(1000);
  
}

//--------------Pokemon

/*

Pokemon:

		Serperior	Blastoize	Arcanine	Goodra	Sylveon	Melmetal
		-----------	---------	----------	------	-------	--------
Vida:	115			105			80			95		110		100
Neutro:	10			12			18			14		12		10
Elem.:	24			24			30			26		24		28

*/

//----------------Setup

void setup()
{
  Wire.begin();
  
  lcd.begin(16, 2); 
  Serial.begin(9600);
  String elegirPokemon (char pokemon);
  int atkEsp (String pokemon1,String pokemon2, int atqEsp);
  void pelea (String pokemon1, String pokemon2,int ataqueNeutro1, int ataqueEsp1, int HPPokemon2);
  lcd.noCursor();
  int CantHP(String poke);
  int CantAtkN (String poke);
  int CantAtkE (String poke);
}

//----------Variables para Funciones

String poke1;
String poke2;
String poke3;
int HP1;
int HP2;
int HP3;
int atqNeutro1;
int atqNeutro2;
int atqNeutro3;
int atqEsp1;
int atqEsp2;
int atqEsp3;

//---------Loop

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Elija su Equipo:");
  char pokemon = pad.waitForKey();
  poke1 = elegirPokemon(pokemon);
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Elija su Segundo");
  lcd.setCursor(0,1);
  lcd.print("Pokemon: ");
  delay(1000);
  char pokemon2 = pad.waitForKey();
  poke2 = elegirPokemon(pokemon2);
  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print("Elija su Tercer");
  lcd.setCursor(0,1);
  lcd.print("Pokemon: ");
  delay(1000);
  char pokemon3 = pad.waitForKey();
  poke3 = elegirPokemon(pokemon3);
  lcd.clear();
  lcd.print("Equipo Pokemon:");
  delay(1000);
  lcd.clear();
  EquipoPokemon(poke1,poke2,poke3);
  pokemon = pad.waitForKey();
  lcd.clear();
  
}
