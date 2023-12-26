typedef struct{
    int data;
    void (*callback)(int);

} Event;

Event events[100];
unsigned int currentEvent = 0;

void register_event(void (*callback)(int), int data){
    Event e = {data,callback};
    events[currentEvent++] = e; 
}

void fire_events(){
    for(int i = 0; i < currentEvent; i++ ){
        events[i].callback(events[i].data);
    }
}

