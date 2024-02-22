
TaskHandle_t Task1;


void setup() {
  // put your setup code here, to run once:
  xTaskCreatePinnedToCore(
    loop2, //nombre de la nueva estructura repetitiva
    "Task_1", //nombre de la funcion , ni idea
    1000, //tamaño de la pila
    NULL, //parametro que le querramos pasar a la nueva tarea, casi siempre es null
    1, //prioridad
    &Task1, //puntero a la nueva tarea
    0 //nucleo de esp utilizado para esa tarea
  );

  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("En nucleo-> " + String(xPortGetCoreID()));
  delay(500);
}

void loop2(void * parameter){
  for(;;){
    Serial.println("\t\t\tEn nucleo-> " + String(xPortGetCoreID()));
    delay(500);
  }

}