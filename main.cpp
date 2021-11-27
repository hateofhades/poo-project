#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

int main()
{
    if(!al_init()) //Initialize Allegro
    {
        printf("Couldn't initialize Allegro!\n");
        return 1;
    }

    if(!al_install_keyboard()) //Try to initialize keyboard
    {
        printf("Couldn't initialize keyboard!\n");
        return 1;
    }

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0); //Run the game at 30fps
    if(!timer)
    {
        printf("Couldn't initialize timer!\n");
        return 1;
    }

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue(); //Create an event queue
    if(!queue)
    {
        printf("Couldn't initialize queue!\n");
        return 1;
    }

    ALLEGRO_DISPLAY* disp = al_create_display(1280, 720); //Create a new window
    if(!disp)
    {
        printf("Couldn't initialize display!\n");
        return 1;
    }

    ALLEGRO_FONT* font = al_create_builtin_font(); //Initialize font
    if(!font)
    {
        printf("Couldn't initialize font!\n");
        return 1;
    }

    al_register_event_source(queue, al_get_keyboard_event_source()); //Listen to keyboard presses
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer)); //Listen to the timer for when the next frame needs to be drawn

    bool done = false;
    bool redraw = true;
    ALLEGRO_EVENT event;

    al_start_timer(timer); //Start the timer
    while(1) //Start the main loop
    {
        al_wait_for_event(queue, &event);

        switch(event.type)
        {
            case ALLEGRO_EVENT_TIMER:
                // game logic goes here.
                redraw = true;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                done = true;
                break;
        }

        if(done)
            break;

        if(redraw && al_is_event_queue_empty(queue))
        {
            al_clear_to_color(al_map_rgb(255, 255, 255));
            al_draw_text(font, al_map_rgb(0, 0, 0), 640, 360, 0, "Escape Room Proiect");
            al_flip_display();

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}