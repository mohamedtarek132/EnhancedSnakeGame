#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace sf;
using namespace std;

struct Check {
    //the snake to make sure that the snake didn't hit the walls or itself
    bool is_the_snake_alive;
    //to make sure that the player started playing 
    bool if_the_player_started_playing;
    //to make sure that the apple was eaten 
    bool is_the_apple_eaten;
    //to make sure that the rotten apple was eaten
    int is_the_rotten_apple_eaten;
    //to make sure that the setting button in game was pressed
    bool is_the_setting_in_game_button_pressed;
    //to make sure that the restart button was pressed
    bool is_the_restart_button_pressed;
    //to make sure that the start button was pressed
    bool is_game_button_pressed;
    //to make sure that the view high score button was pressed
    bool is_ranking_button_pressed;
    //to make sure that the setting button was pressed
    bool is_setting_button_pressed;
    //to make sure that the audio button in the settings menu was pressed
    bool is_audio_button_pressed;
    //to make sure that the opening ended
    bool did_the_opening_end;

    bool is_change_snake_button_pressed;

    bool is_snake_1_being_used;

    bool is_snake_2_being_used;

    bool is_snake_3_being_used;

    bool is_snake_4_being_used;

    bool is_snake_changing_colors;

    bool is_resize_button_pressed = 0;
};
struct shapetextures {
    Texture resumeicontexture;
    Texture    restarticontexture;
    Texture   snakeheadtexture;
    Texture  rottenappletexture;
    Texture appletexture;
    Texture snaketurntexture;
    Texture snakebodytexture;
    Texture  snaketailtexture;
    Texture exiticontexture;
    Texture opening_texture;
    Texture main_menu_page_texture;
    Texture setting_page_texture;
    Texture ranking_page_texture;
    Texture setting_music_page_texture;
    Texture exit_icon_in_setting_music_page_texture;
    Texture game_over_texture;
    Texture change_snake_page_texture;
    Texture Truee;
    Texture* resume_icon_texture;
    Texture* restart_icon_texture;
    Texture* apple_icon_texture;
    Texture* rotten_apple_icon_texture;
    Texture* snake_head_texture;
    Texture* exit_icon_texture;
    Texture* snake_turn_texture;
    Texture* snake_body_texture;
    Texture* snake_tail_texture;
};
struct shape {
    CircleShape apple_icon;
    CircleShape rotten_apple_icon;

    Sprite opening;
    Sprite main_menu_page;
    Sprite setting_page;
    Sprite ranking_page;
    Sprite setting_music_page;
    Sprite exit_icon_in_setting_music_page;
    Sprite game_over;
    Sprite change_snake_page;
    Sprite Tru_ee;

    RectangleShape pause_icon;
    RectangleShape resume_icon;
    RectangleShape restart_icon;
    RectangleShape exit_icon;
};

int window_width = 1300, window_height = 800;
// The maximum number of square for the snake
const int MAX_NUMBER_OF_SQUARES = 1000;

/* the speed array to make the snake parts to follow each other the 0 in the first dimension means its direction in the x axis and
 the 1 in the first dimension means its direction in the y axis*/
int speed[MAX_NUMBER_OF_SQUARES][2];
//control the size of the snake
float snake_size_and_speed = 30;

Text text;

Texture body___topleft1;
Texture* body_topleft_texture1 = &body___topleft1;

Texture body___bottomright1;
Texture* body_bottomright_texture1 = &body___bottomright1;

Texture body___bottomleft1;
Texture* body_bottomleft_texture1 = &body___bottomleft1;

Texture body___horizontal1;
Texture* body_horizontal_texture1 = &body___horizontal1;

Texture body___topright1;
Texture* body_topright_texture1 = &body___topright1;

Texture body___vertical1;
Texture* body_vertical_texture1 = &body___vertical1;

Texture head___down1;
Texture* head_down_texture1 = &head___down1;

Texture head___left1;
Texture* head_left_texture1 = &head___left1;

Texture head___right1;
Texture* head_right_texture1 = &head___right1;

Texture head___up1;
Texture* head_up_texture1 = &head___up1;

Texture tail___down1;
Texture* tail_down_texture1 = &tail___down1;

Texture tail___left1;
Texture* tail_left_texture1 = &tail___left1;

Texture tail___right1;
Texture* tail_right_texture1 = &tail___right1;

Texture tail___up1;
Texture* tail_up_texture1 = &tail___up1;


Texture body___topright2;
Texture* body_topright_texture2 = &body___topright2;

Texture body___horizontal2;
Texture* body_horizontal_texture2 = &body___horizontal2;

Texture head___right2;
Texture* head_right_texture2 = &head___right2;

Texture tail___left2;
Texture* tail_left_texture2 = &tail___left2;



Sound apple_eating_sound, rotten_apple_eating_sound, losing_sound;

Music music;

RenderWindow window(VideoMode(window_width, window_height), "Snake Game");

RectangleShape snake[MAX_NUMBER_OF_SQUARES];

Texture game_background_texture;

Sprite game_background;

void sizenposition();

void collision(shape shapes, int& number_of_eaten_apples, Check& check, int ranking[], int& collision_counter);

void update_game(shape& shapes, int& counter, Check& check, int number_of_eaten_apples);

void snake_movement(Check& check);

void changexny();

void draw_game(shape& shapes, int& number_of_eaten_apples, Check& check, Font font, shapetextures texture);

void set_rotation(int number_of_eaten_apples, int square_number);

void set_color(int square_number, int number_of_eaten_apples, Check check);

void set_texture(int number_of_eaten_apples, Check check, shapetextures& textures);

void randapple(shape& shapes, Check& check, int number_of_eaten_apples);

void randrottenapple(shape& shapes, Check& check, int number_of_eaten_apples);

void apple_counter(int number_of_eaten_apples, Check check);

void draw_resume_icon(shape shapes, Check check);

void draw_restart_icon(shape shapes, Check check);

void draw_exit_icon(shape shapes, Check check);

void drawMainMenu(Font& font, shape shapes, Check check);

void drawSettingsMenu(Font& font, shape shapes, Check check);

void draw_view_high_score_menu(shape shapes, Text text, int ranking[], Check check);

void changing_ranking(int number_of_eaten_apples, int ranking[]);

void draw_audio_settings(shape shapes, Check check);

void draw_change_color(shape shapes, Check& check);

void change_size(shape& shapes);

int main() {
    // a counter to make the snake move slower by decreasing the number of times the snake will move per second
    int game_counter = 0;
    // a counter to keep the opening playing for a second or two
    int opening_counter = 0;
    // the number of eaten apples in the game to make the snake grow taller
    int number_of_eaten_apples = 0;
    //to keep record of the highest 3 scores in the game
    int ranking[3] = {};

    int collision_counter = 0;
    //1 for check snake , 0 for if the player started playing, 0 for is the apple eaten,
    Check check = {};
    check.is_the_snake_alive = 1;
    check.is_snake_1_being_used = 1;

    shapetextures textures;

    shape shapes;

    SoundBuffer apple_eating_sound_buffer, rotten_apple_eating_sound_buffer, losing_sound_buffer;

    Font font;

    textures.resume_icon_texture = &textures.resumeicontexture;
    textures.restart_icon_texture = &textures.restarticontexture;
    textures.exit_icon_texture = &textures.exiticontexture;
    textures.apple_icon_texture = &textures.appletexture;
    textures.rotten_apple_icon_texture = &textures.rottenappletexture;
    textures.snake_head_texture = &textures.snakeheadtexture;

    //loading backgroung music
    music.openFromFile("Snake Game _music.wav");
    music.setLoop(true);
    music.play();
    music.setVolume(0);

    //loading fong and setting the font of the text
    font.loadFromFile("font file 2.ttf");
    text.setFont(font);

    //loading sound of the apple being eaten
    apple_eating_sound_buffer.loadFromFile("apple_crunch.wav");
    apple_eating_sound.setBuffer(apple_eating_sound_buffer);

    //loading sound of the rotten apple being eaten
    rotten_apple_eating_sound_buffer.loadFromFile("player_hurt.wav");
    rotten_apple_eating_sound.setBuffer(rotten_apple_eating_sound_buffer);

    //loading sound of the snake diying
    losing_sound_buffer.loadFromFile("gameover.wav");
    losing_sound.setBuffer(losing_sound_buffer);


    //loading textures

    //loading texture of the restart icon 
    textures.restarticontexture.loadFromFile("restart_button.png");
    textures.restarticontexture.setSmooth(1);
    shapes.restart_icon.setTexture(textures.restart_icon_texture);

    //loading texture of the resume icon 
    textures.resumeicontexture.loadFromFile("resume_button.png");
    textures.resumeicontexture.setSmooth(1);
    shapes.resume_icon.setTexture(textures.resume_icon_texture);

    //loading texture of the exit icon
    textures.exiticontexture.loadFromFile("exit_button.png");
    textures.exiticontexture.setSmooth(1);
    shapes.exit_icon.setTexture(textures.exit_icon_texture);

    //loading texture of the apple icon
    textures.appletexture.loadFromFile("apple.png", IntRect(0, 182, 61, 70));
    shapes.apple_icon.setTexture(textures.apple_icon_texture);

    //loading texture of the rotten apple
    textures.rottenappletexture.loadFromFile("rotten_apple-removebg-preview.png");
    shapes.rotten_apple_icon.setTexture(textures.rotten_apple_icon_texture);

    //loading texture of the game background
    game_background_texture.loadFromFile("Background.png");
    game_background.setTexture(game_background_texture);
    game_background.setScale((1300.0 / 1800.0), (800.0 / 1300.0));

    //loading textures for the snake
    textures.snakeheadtexture.loadFromFile("Snake sprite sheet.png", IntRect(0, 2, 40, 40));
    textures.snakeheadtexture.setSmooth(1);
    textures.snakebodytexture.loadFromFile("Snake sprite sheet.png", IntRect(84, 85, 40, 40));
    textures.snakebodytexture.setSmooth(1);
    textures.snaketurntexture.loadFromFile("Snake sprite sheet.png", IntRect(42, 0, 40, 40));
    textures.snaketurntexture.setSmooth(1);
    textures.snaketailtexture.loadFromFile("Snake sprite sheet.png", IntRect(44, 85, 40, 40));
    textures.snaketailtexture.setSmooth(1);


    body___topleft1.loadFromFile("body_topleft.png");

    body___bottomright1.loadFromFile("body_bottomright.png");

    body___bottomleft1.loadFromFile("body_bottomleft.png");

    body___horizontal1.loadFromFile("body_horizontal.png");

    body___topright1.loadFromFile("body_topright.png");

    body___vertical1.loadFromFile("body_vertical.png");

    head___down1.loadFromFile("head_down.png");

    head___left1.loadFromFile("head_left.png");

    head___right1.loadFromFile("head_right.png");

    head___up1.loadFromFile("head_up.png");

    tail___down1.loadFromFile("tail_down.png");

    tail___left1.loadFromFile("tail_left.png");

    tail___right1.loadFromFile("tail_right.png");

    tail___up1.loadFromFile("tail_up.png");


    body___topright2.loadFromFile("body top right.png");

    body___horizontal2.loadFromFile("body horizontal.png");

    head___right2.loadFromFile("head right.png");

    tail___left2.loadFromFile("tail left.png");



    /*loading texture for the opening*/
    textures.opening_texture.loadFromFile("opening page.png");
    shapes.opening.setTexture(textures.opening_texture);
    shapes.opening.setScale((1300.0 / 1800.0), (800.0 / 1300.0));

    //loading texture for the main menu
    textures.main_menu_page_texture.loadFromFile("main menu.png");
    shapes.main_menu_page.setTexture(textures.main_menu_page_texture);
    shapes.main_menu_page.setScale((1300.0 / 1800), (800.0 / 1300));

    //loading texture for the setting page
    textures.setting_page_texture.loadFromFile("setting menu.png");
    textures.setting_page_texture.setSmooth(1);
    shapes.setting_page.setTexture(textures.setting_page_texture);
    shapes.setting_page.setScale((1300.0 / 1800), (800.0 / 1300.0));

    //loading texture for the setting music page
    textures.setting_music_page_texture.loadFromFile("Setting music page.png");
    shapes.setting_music_page.setTexture(textures.setting_music_page_texture);
    shapes.setting_music_page.setScale((1300.0 / 1800.0), (800.0 / 1300.0));

    //loading texture for the exit setting music 
    textures.exit_icon_in_setting_music_page_texture.loadFromFile("exit setting music page.png");
    shapes.exit_icon_in_setting_music_page.setTexture(textures.exit_icon_in_setting_music_page_texture);
    shapes.exit_icon_in_setting_music_page.setScale(0.7, 0.7);

    //loading texture for the ranking page
    textures.ranking_page_texture.loadFromFile("ranking page.png");
    shapes.ranking_page.setTexture(textures.ranking_page_texture);
    shapes.ranking_page.setScale((1300.0 / 1800.0), (800.0 / 1300.0));

    //loading texturer for the game over 
    textures.game_over_texture.loadFromFile("game_over.png");
    shapes.game_over.setTexture(textures.game_over_texture);
    shapes.game_over.setScale(0.2, 0.2);

    textures.change_snake_page_texture.loadFromFile("changing snake.png");
    shapes.change_snake_page.setTexture(textures.change_snake_page_texture);

    textures.Truee.loadFromFile("true.png");
    shapes.Tru_ee.setTexture(textures.Truee);

    window.setFramerateLimit(70);

    sizenposition();

    //to keep the window open
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            //to close the window with the close button
            if ((event.type == Event::Closed) || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
            if (event.type == Event::Resized) {
                window.create(VideoMode(1300, 800), "Snake game", Style::Fullscreen);
                check.is_resize_button_pressed = 1;
                snake_size_and_speed = 40;
                change_size(shapes);
            }
        }

       
        //to reset the game counter so it won't get past the integer limit
        if (game_counter == 1000000)
            game_counter = 0;
        if (collision_counter == 1000000)
            collision_counter == 1;
        //to make sure that the opening ended and that you won't press on any button while it is working
        if (check.did_the_opening_end)
            collision(shapes, number_of_eaten_apples, check, ranking, collision_counter);

        //to make sure that the snake didn't hit itself or the wall,that you didn't press on the in game setting,and that you pressed 
        //start
        if (check.is_the_snake_alive && !check.is_the_setting_in_game_button_pressed && check.is_game_button_pressed)
            update_game(shapes, game_counter, check, number_of_eaten_apples);

        else if (check.is_the_restart_button_pressed) {
            number_of_eaten_apples = 0;
            sizenposition();
            check.is_the_snake_alive = 1;
            check.if_the_player_started_playing = 0;
            check.is_the_restart_button_pressed = 0;
            check.is_the_setting_in_game_button_pressed = 0;
        }
        if (check.is_game_button_pressed) {
            draw_game(shapes, number_of_eaten_apples, check, font, textures);

        }
        else if (opening_counter <= 200) {
            window.clear();
            window.draw(shapes.opening);
            window.display();
            opening_counter++;
        }
        else if (check.is_setting_button_pressed) {

            drawSettingsMenu(font, shapes, check);
        }
        else if (check.is_ranking_button_pressed)
        {
            draw_view_high_score_menu(shapes, text, ranking, check);

        }
        else if (check.is_audio_button_pressed) {
            draw_audio_settings(shapes, check);
        }
        else if (check.is_change_snake_button_pressed)
        {
            draw_change_color(shapes, check);
        }
        else {
            check.did_the_opening_end = 1;
            drawMainMenu(font, shapes, check);
            sizenposition();
            check.is_the_snake_alive = 1;
            check.if_the_player_started_playing = 0;
            check.is_the_restart_button_pressed = 0;
            check.is_the_setting_in_game_button_pressed = 0;
            number_of_eaten_apples = 0;

        }

    }
    return 0;
}

void change_size(shape& shapes) {
    shapes.main_menu_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.ranking_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.setting_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.opening.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.change_snake_page.setScale(VideoMode::getDesktopMode().width / 1300.0, VideoMode::getDesktopMode().height / 800.0);
    game_background.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.setting_music_page.setScale(VideoMode::getDesktopMode().width / 1800.0, VideoMode::getDesktopMode().height / 1300.0);
    shapes.restart_icon.setScale(1.5, 1.5);
    shapes.exit_icon.setScale(1.5, 1.5);
    shapes.resume_icon.setScale(1.5, 1.5);
    shapes.game_over.setScale(0.25, 0.25);
    shapes.exit_icon_in_setting_music_page.setScale(1, 1);
}

//to make all of the squares to have the same size, origin,and initial speed (+ve x direction) 
void sizenposition() {

    for (int i = 0; i < MAX_NUMBER_OF_SQUARES; i++) {
        snake[i].setSize(Vector2f(snake_size_and_speed, snake_size_and_speed));
        snake[i].setOrigin(snake_size_and_speed / 2, snake_size_and_speed / 2);
        snake[i].setPosition(Vector2f(670 + snake_size_and_speed * (2 - i), 386));
        speed[i][0] = snake_size_and_speed;
        speed[i][1] = 0;
    }
}

//to know whether the snake collided or not with the boundries,itself,apple,or rotten apple and to check that you pressed on 
//any button in the game
void collision(shape shapes, int& number_of_eaten_apples, Check& check, int ranking[], int& collision_counter) {

    bool left_or_right_mouse_button_pressed = Mouse::isButtonPressed(Mouse::Left) || Mouse::isButtonPressed(Mouse::Right);
    bool space_button_is_pressed = Keyboard::isKeyPressed(Keyboard::Space);
    bool escape_button_is_pressed = Keyboard::isKeyPressed(Keyboard::Escape);

    for (int i = 3; i < number_of_eaten_apples + 2; i++) {
        if (snake[0].getGlobalBounds().intersects(snake[i].getGlobalBounds()) && check.is_the_snake_alive == 1) {
            check.is_the_snake_alive = 0;
            losing_sound.play();
            changing_ranking(number_of_eaten_apples, ranking);
            break;
        }
    }
    bool did_snake_hit_right_side_of_the_box = ((int)snake[0].getGlobalBounds().left + (int)snake[0].getGlobalBounds().width) >= 1150;
    bool did_snake_hit_left_side_of_the_box = snake[0].getGlobalBounds().left <= 145;
    bool did_snake_hit_bottom_of_the_box = (snake[0].getGlobalBounds().top + snake[0].getGlobalBounds().height) >=
        (730);
    bool did_snake_hit_top_of_the_box = snake[0].getGlobalBounds().top - 30 <= 70;

    if (check.is_resize_button_pressed) {
        did_snake_hit_right_side_of_the_box = ((int)snake[0].getGlobalBounds().left + (int)snake[0].getGlobalBounds().width) >= 1707;
        did_snake_hit_left_side_of_the_box = snake[0].getGlobalBounds().left <= 213;
        did_snake_hit_bottom_of_the_box = (snake[0].getGlobalBounds().top + snake[0].getGlobalBounds().height) >=
            (982);
        did_snake_hit_top_of_the_box = snake[0].getGlobalBounds().top <= 95;
    }

    if ((did_snake_hit_top_of_the_box || did_snake_hit_bottom_of_the_box || did_snake_hit_left_side_of_the_box ||
        did_snake_hit_right_side_of_the_box) && check.is_the_snake_alive == 1) {
        check.is_the_snake_alive = 0;
        changing_ranking(number_of_eaten_apples, ranking);
        losing_sound.play();
    }

    if (snake[0].getGlobalBounds().intersects(shapes.apple_icon.getGlobalBounds()) && check.is_the_apple_eaten == 0) {
        check.is_the_apple_eaten = 1;
        number_of_eaten_apples++;
        apple_eating_sound.play();
    }

    if (snake[0].getGlobalBounds().intersects(shapes.rotten_apple_icon.getGlobalBounds()) && check.is_the_rotten_apple_eaten == 0
        && number_of_eaten_apples > 0) {
        number_of_eaten_apples--;
        check.is_the_rotten_apple_eaten = 1;
        rotten_apple_eating_sound.play();
    }

    //in game buttons
    int icon_width = 765 - 580;
    int icon_height = 485 - 425;
    int in_game_buttons_x_position = 580;
    int in_game_first_button = 225;
    int in_game_space_between_buttons = 40;
    int in_game_second_button = in_game_first_button + icon_height + in_game_space_between_buttons;
    int in_game_third_button = in_game_second_button + icon_height + in_game_space_between_buttons;
    if (check.is_resize_button_pressed) {
        icon_width = 1125 - 845;
        icon_height = 425 - 340;
        in_game_buttons_x_position = 845;
        in_game_space_between_buttons = 15;
        in_game_first_button = 340;
        in_game_second_button = in_game_first_button + icon_height + in_game_space_between_buttons;
        in_game_third_button = in_game_second_button + icon_height + in_game_space_between_buttons;
    }

    bool mouse_position_is_inside_resume_icon_box_in_game = 0;
    bool mouse_position_is_inside_restart_icon_box_in_game = 0;
    bool mouse_position_is_inside_exit_icon_box_in_game = 0;
    bool mouse_position_is_inside_pause_icon_box_in_game =
        Mouse::getPosition(window).x >= 1200 &&
        Mouse::getPosition(window).x <= 1300 &&
        Mouse::getPosition(window).y >= 5 &&
        Mouse::getPosition(window).y <= 75;
    if (check.is_resize_button_pressed) {
        mouse_position_is_inside_pause_icon_box_in_game =
            Mouse::getPosition(window).x >= 1773 &&
            Mouse::getPosition(window).x <= 1920 &&
            Mouse::getPosition(window).y >= 5 &&
            Mouse::getPosition(window).y <= 100;
    }
    int time = 15;
    if (check.is_resize_button_pressed)
        time = 35;
    if (collision_counter % time == 0) {
        if (check.is_the_snake_alive) {
            if (check.is_resize_button_pressed) {
                mouse_position_is_inside_resume_icon_box_in_game =
                    Mouse::getPosition(window).x >= in_game_buttons_x_position &&
                    Mouse::getPosition(window).x <= in_game_buttons_x_position + icon_width &&
                    Mouse::getPosition(window).y >= in_game_first_button &&
                    Mouse::getPosition(window).y <= (in_game_first_button + icon_height);

                mouse_position_is_inside_restart_icon_box_in_game =
                    Mouse::getPosition(window).x >= in_game_buttons_x_position &&
                    Mouse::getPosition(window).x <= in_game_buttons_x_position + icon_width &&
                    Mouse::getPosition(window).y >= in_game_second_button &&
                    Mouse::getPosition(window).y <= (in_game_second_button + icon_height);

                mouse_position_is_inside_exit_icon_box_in_game =
                    Mouse::getPosition(window).x >= in_game_buttons_x_position &&
                    Mouse::getPosition(window).x <= in_game_buttons_x_position + icon_width &&
                    Mouse::getPosition(window).y >= in_game_third_button &&
                    Mouse::getPosition(window).y <= in_game_third_button + icon_height;
            }
        }
        else {
            if (!check.is_resize_button_pressed) {
                mouse_position_is_inside_restart_icon_box_in_game =
                    Mouse::getPosition(window).x >= 430 &&
                    Mouse::getPosition(window).x <= (430 + icon_width) &&
                    Mouse::getPosition(window).y >= 325 &&
                    Mouse::getPosition(window).y <= (325 + icon_height);

                mouse_position_is_inside_exit_icon_box_in_game =
                    Mouse::getPosition(window).x >= 660 &&
                    Mouse::getPosition(window).x <= 660 + icon_width &&
                    Mouse::getPosition(window).y >= 325 &&
                    Mouse::getPosition(window).y <= 325 + icon_height;
            }
            else {
                mouse_position_is_inside_restart_icon_box_in_game =
                    Mouse::getPosition(window).x >= 645 &&
                    Mouse::getPosition(window).x <= 925 &&
                    Mouse::getPosition(window).y >= 440 &&
                    Mouse::getPosition(window).y <= (525);

                mouse_position_is_inside_exit_icon_box_in_game =
                    Mouse::getPosition(window).x >= 1045 &&
                    Mouse::getPosition(window).x <= 1325 &&
                    Mouse::getPosition(window).y >= 440 &&
                    Mouse::getPosition(window).y <= 530;
            }

        }

        if ((left_or_right_mouse_button_pressed && mouse_position_is_inside_pause_icon_box_in_game) || space_button_is_pressed) {
            check.is_the_setting_in_game_button_pressed = 1;
        }
        if (check.is_game_button_pressed && left_or_right_mouse_button_pressed && !check.is_ranking_button_pressed
            && !check.is_setting_button_pressed && !check.is_audio_button_pressed && !check.is_change_snake_button_pressed) {

            if (mouse_position_is_inside_resume_icon_box_in_game && check.is_the_setting_in_game_button_pressed) {
                check.is_the_setting_in_game_button_pressed = 0;
            }

            if (((mouse_position_is_inside_restart_icon_box_in_game)) && (check.is_the_snake_alive == 0 ||
                check.is_the_setting_in_game_button_pressed)) {
                check.is_the_restart_button_pressed = 1;
            }

            if (mouse_position_is_inside_exit_icon_box_in_game && (check.is_the_snake_alive == 0 || check.is_the_setting_in_game_button_pressed)) {
                check.is_game_button_pressed = 0;
            }
        }

        //main menu buttons

        int left_x_position_of_the_main_menu_buttons = 560;
        int width_of_main_menu_buttons = 190;
        int height_of_main_menu_buttons = 50;
        int first_button = 460;
        int space_between_main_menu_buttons = 45;
        int second_button = first_button + space_between_main_menu_buttons + height_of_main_menu_buttons;
        int third_button = second_button + space_between_main_menu_buttons + height_of_main_menu_buttons;
        int setting_icon_width = 145 - 30;
        int setting_icon_height = 755 - 670;
        int setting_icon_x_position = 30;
        int setting_icon_y_position = 670;
        if (check.is_resize_button_pressed) {
            left_x_position_of_the_main_menu_buttons = 825;
            width_of_main_menu_buttons = 1105 - 825;
            height_of_main_menu_buttons = 80;
            first_button = 600;
            space_between_main_menu_buttons = 45;
            second_button = first_button + space_between_main_menu_buttons + height_of_main_menu_buttons;
            third_button = second_button + space_between_main_menu_buttons + height_of_main_menu_buttons;
            setting_icon_width = 215 - 45;
            setting_icon_height = 1015 - 905;
            setting_icon_x_position = 45;
            setting_icon_y_position = 905;
        }

        bool mouse_position_is_inside_start_button_in_main_menu =
            Mouse::getPosition(window).x >= left_x_position_of_the_main_menu_buttons &&
            Mouse::getPosition(window).x <= left_x_position_of_the_main_menu_buttons + width_of_main_menu_buttons &&
            Mouse::getPosition(window).y >= first_button &&
            Mouse::getPosition(window).y <= first_button + height_of_main_menu_buttons;
        bool mouse_position_is_inside_view_high_score_button_in_main_menu =
            Mouse::getPosition(window).x >= left_x_position_of_the_main_menu_buttons &&
            Mouse::getPosition(window).x <= left_x_position_of_the_main_menu_buttons + width_of_main_menu_buttons &&
            Mouse::getPosition(window).y >= second_button &&
            Mouse::getPosition(window).y <= second_button + height_of_main_menu_buttons;

        bool mouse_position_is_inside_exit_button_in_main_menu =
            Mouse::getPosition(window).x >= left_x_position_of_the_main_menu_buttons &&
            Mouse::getPosition(window).x <= (left_x_position_of_the_main_menu_buttons + width_of_main_menu_buttons) &&
            Mouse::getPosition(window).y >= third_button &&
            Mouse::getPosition(window).y <= third_button + height_of_main_menu_buttons;

        bool mouse_position_is_inside_setting_button_in_main_menu =
            Mouse::getPosition(window).x >= setting_icon_x_position &&
            Mouse::getPosition(window).x <= setting_icon_x_position + setting_icon_width &&
            Mouse::getPosition(window).y >= setting_icon_y_position &&
            Mouse::getPosition(window).y <= setting_icon_y_position + setting_icon_height;

        if (left_or_right_mouse_button_pressed && !check.is_game_button_pressed && !check.is_ranking_button_pressed
            && !check.is_setting_button_pressed && !check.is_audio_button_pressed && check.is_change_snake_button_pressed == 0) {
            if ((mouse_position_is_inside_start_button_in_main_menu))
            {
                // "Start" button pressed
                check.is_game_button_pressed = 1;
                // start the game
            }
            else if ((mouse_position_is_inside_view_high_score_button_in_main_menu))
            {
                check.is_ranking_button_pressed = 1;
                // "View High Score" button pressed
                // show the high scores
            }
            else if ((mouse_position_is_inside_setting_button_in_main_menu))
            {
                // "Settings" button pressed
                check.is_setting_button_pressed = 1;
            }
            else if ((mouse_position_is_inside_exit_button_in_main_menu))
            {
                // "Exit" button pressed
                window.close();
            }
        }

        //ranking buttons
        bool mouse_position_is_inside_exit_button_in_ranking_page =
            Mouse::getPosition(window).x >= 825 &&
            Mouse::getPosition(window).x <= 925 &&
            Mouse::getPosition(window).y >= 645 &&
            Mouse::getPosition(window).y <= 730;
        if (check.is_resize_button_pressed) {
            mouse_position_is_inside_exit_button_in_ranking_page =
                Mouse::getPosition(window).x >= 1220 &&
                Mouse::getPosition(window).x <= 1365 &&
                Mouse::getPosition(window).y >= 870 &&
                Mouse::getPosition(window).y <= 990;
        }
        if (left_or_right_mouse_button_pressed && mouse_position_is_inside_exit_button_in_ranking_page && check.is_ranking_button_pressed &&
            !check.is_game_button_pressed && !check.is_setting_button_pressed && check.is_audio_button_pressed == 0 &&
            check.is_change_snake_button_pressed == 0) {
            check.is_ranking_button_pressed = 0;
        }
        //setting buttons
        int setting_buttons_x_position = 525;
        int setting_buttons_width = 780 - 525;
        int setting_buttons_height = 85;
        int setting_space_between_buttons = 15;
        int setting_first_button = 300;
        int setting_second_button = setting_first_button + setting_buttons_height + setting_space_between_buttons;
        int setting_third_button = setting_second_button + setting_buttons_height + setting_space_between_buttons;
        if (check.is_resize_button_pressed) {
            setting_buttons_x_position = 780;
            setting_buttons_width = 1150 - 780;
            setting_buttons_height = 520 - 405;
            setting_space_between_buttons = 540 - 520;
            setting_first_button = 405;
            setting_second_button = setting_first_button + setting_buttons_height + setting_space_between_buttons;
            setting_third_button = setting_second_button + setting_buttons_height + setting_space_between_buttons;
        }
        if (Mouse::isButtonPressed(Mouse::Right)) {
            cout << Mouse::getPosition(window).x << ' ' << Mouse::getPosition(window).y << endl;
        }
        bool mouse_position_is_inside_audio_button_in_setting_page =
            Mouse::getPosition(window).x >= setting_buttons_x_position &&
            Mouse::getPosition(window).x <= setting_buttons_x_position + setting_buttons_width &&
            Mouse::getPosition(window).y >= setting_first_button &&
            Mouse::getPosition(window).y <= setting_first_button + setting_buttons_height;
        bool mouse_position_is_inside_change_color_button_in_setting_page =
            Mouse::getPosition(window).x >= setting_buttons_x_position &&
            Mouse::getPosition(window).x <= setting_buttons_x_position + setting_buttons_width &&
            Mouse::getPosition(window).y >= setting_second_button &&
            Mouse::getPosition(window).y <= setting_second_button + setting_buttons_height;
        bool mouse_position_is_inside_exit_button_in_setting_page =
            Mouse::getPosition(window).x >= setting_buttons_x_position &&
            Mouse::getPosition(window).x <= setting_buttons_x_position + setting_buttons_width &&
            Mouse::getPosition(window).y >= setting_third_button &&
            Mouse::getPosition(window).y <= setting_third_button + setting_buttons_height;

        if (check.is_setting_button_pressed && left_or_right_mouse_button_pressed && !check.is_audio_button_pressed &&
            !check.is_ranking_button_pressed && !check.is_game_button_pressed && !check.is_change_snake_button_pressed) {

            if (mouse_position_is_inside_audio_button_in_setting_page) {
                check.is_audio_button_pressed = 1;
                check.is_setting_button_pressed = 0;
            }
            else if (mouse_position_is_inside_change_color_button_in_setting_page) {
                check.is_change_snake_button_pressed = 1;
                check.is_setting_button_pressed = 0;
            }
            else if (mouse_position_is_inside_exit_button_in_setting_page) {
                check.is_setting_button_pressed = 0;
            }
        }
        //audio buttons
        bool mouse_position_is_inside_ON_Audio_in_audio_setting_page =
            Mouse::getPosition(window).x >= 615 &&
            Mouse::getPosition(window).x <= 683 &&
            Mouse::getPosition(window).y >= 390 &&
            Mouse::getPosition(window).y <= 445;
        bool mouse_position_is_inside_OFF_Audio_in_setting_page =
            Mouse::getPosition(window).x >= 739 &&
            Mouse::getPosition(window).x <= 800 &&
            Mouse::getPosition(window).y >= 390 &&
            Mouse::getPosition(window).y <= 445;
        bool mouse_position_is_inside_ON_Music_in_setting_page =
            Mouse::getPosition(window).x >= 615 &&
            Mouse::getPosition(window).x <= 683 &&
            Mouse::getPosition(window).y >= 523 &&
            Mouse::getPosition(window).y <= 576;
        bool mouse_position_is_inside_OFF_Music_in_setting_page =
            Mouse::getPosition(window).x >= 739 &&
            Mouse::getPosition(window).x <= 800 &&
            Mouse::getPosition(window).y >= 523 &&
            Mouse::getPosition(window).y <= 576;
        bool mouse_position_is_inside_exit_button_in_music_setting_page =
            Mouse::getPosition(window).x >= 845 &&
            Mouse::getPosition(window).x <= 925 &&
            Mouse::getPosition(window).y >= 255 &&
            Mouse::getPosition(window).y <= 330;
        if (check.is_resize_button_pressed) {
            mouse_position_is_inside_ON_Audio_in_audio_setting_page =
                Mouse::getPosition(window).x >= 910 &&
                Mouse::getPosition(window).x <= 1005 &&
                Mouse::getPosition(window).y >= 530 &&
                Mouse::getPosition(window).y <= 600;
            mouse_position_is_inside_OFF_Audio_in_setting_page =
                Mouse::getPosition(window).x >= 1090 &&
                Mouse::getPosition(window).x <= 1185 &&
                Mouse::getPosition(window).y >= 530 &&
                Mouse::getPosition(window).y <= 600;
            mouse_position_is_inside_ON_Music_in_setting_page =
                Mouse::getPosition(window).x >= 910 &&
                Mouse::getPosition(window).x <= 1005 &&
                Mouse::getPosition(window).y >= 705 &&
                Mouse::getPosition(window).y <= 775;
            mouse_position_is_inside_OFF_Music_in_setting_page =
                Mouse::getPosition(window).x >= 1085 &&
                Mouse::getPosition(window).x <= 1180 &&
                Mouse::getPosition(window).y >= 710 &&
                Mouse::getPosition(window).y <= 780;
            mouse_position_is_inside_exit_button_in_music_setting_page =
                Mouse::getPosition(window).x >= 1195 &&
                Mouse::getPosition(window).x <= 1305 &&
                Mouse::getPosition(window).y >= 325 &&
                Mouse::getPosition(window).y <= 435;
        }
        if (left_or_right_mouse_button_pressed && check.is_audio_button_pressed && !check.is_change_snake_button_pressed &&
            !check.is_game_button_pressed && !check.is_ranking_button_pressed && !check.is_setting_button_pressed) {
            if (mouse_position_is_inside_ON_Audio_in_audio_setting_page) {
                apple_eating_sound.setVolume(100);
                losing_sound.setVolume(100);
                rotten_apple_eating_sound.setVolume(100);
            }
            else if (mouse_position_is_inside_OFF_Audio_in_setting_page) {
                apple_eating_sound.setVolume(0);
                losing_sound.setVolume(0);
                rotten_apple_eating_sound.setVolume(0);
            }
            else if (mouse_position_is_inside_ON_Music_in_setting_page) {
                music.setVolume(100);
            }
            else if (mouse_position_is_inside_OFF_Music_in_setting_page) {
                music.setVolume(0);
            }
            else if (mouse_position_is_inside_exit_button_in_music_setting_page) {
                check.is_audio_button_pressed = 0;
                check.is_setting_button_pressed = 1;
            }
        }

        bool mouse_position_is_inside_Exit_in_change_color_page =
            Mouse::getPosition(window).x >= 556 &&
            Mouse::getPosition(window).x <= 725 &&
            Mouse::getPosition(window).y >= 527 &&
            Mouse::getPosition(window).y <= 574;
        bool mouse_position_is_inside_first_snake_in_change_color_page =
            Mouse::getPosition(window).x >= 632 &&
            Mouse::getPosition(window).x <= 674 &&
            Mouse::getPosition(window).y >= 330 &&
            Mouse::getPosition(window).y <= 373;
        bool mouse_position_is_inside_second_snake_in_change_color_page =
            Mouse::getPosition(window).x >= 439 &&
            Mouse::getPosition(window).x <= 483 &&
            Mouse::getPosition(window).y >= 330 &&
            Mouse::getPosition(window).y <= 373;
        bool mouse_position_is_inside_third_snake_in_change_color_page =
            Mouse::getPosition(window).x >= 823 &&
            Mouse::getPosition(window).x <= 867 &&
            Mouse::getPosition(window).y >= 330 &&
            Mouse::getPosition(window).y <= 373;
        bool mouse_position_is_inside_forth_snake_in_change_color_page =
            Mouse::getPosition(window).x >= 535 &&
            Mouse::getPosition(window).x <= 578 &&
            Mouse::getPosition(window).y >= 330 &&
            Mouse::getPosition(window).y <= 373;
        bool mouse_position_is_inside_first_color_option_in_change_color_page =
            Mouse::getPosition(window).x >= 523 &&
            Mouse::getPosition(window).x <= 567 &&
            Mouse::getPosition(window).y >= 496 &&
            Mouse::getPosition(window).y <= 539;
        bool mouse_position_is_inside_second_color_option_in_change_color_page =
            Mouse::getPosition(window).x >= 689 &&
            Mouse::getPosition(window).x <= 733 &&
            Mouse::getPosition(window).y >= 496 &&
            Mouse::getPosition(window).y <= 539;
        if (check.is_resize_button_pressed) {
            mouse_position_is_inside_Exit_in_change_color_page =
                Mouse::getPosition(window).x >= 810 &&
                Mouse::getPosition(window).x <= 1075 &&
                Mouse::getPosition(window).y >= 710 &&
                Mouse::getPosition(window).y <= 775;
            mouse_position_is_inside_first_snake_in_change_color_page =
                Mouse::getPosition(window).x >= 685 &&
                Mouse::getPosition(window).x <= 760 &&
                Mouse::getPosition(window).y >= 420 &&
                Mouse::getPosition(window).y <= 490;
            mouse_position_is_inside_second_snake_in_change_color_page =
                Mouse::getPosition(window).x >= 760 + (925 - 760) &&
                Mouse::getPosition(window).x <= 760 + (925 - 760) + (760 - 685) &&
                Mouse::getPosition(window).y >= 420 &&
                Mouse::getPosition(window).y <= 490;
            mouse_position_is_inside_third_snake_in_change_color_page =
                Mouse::getPosition(window).x >= 760 + (925 - 760) * 2 + (760 - 685) &&
                Mouse::getPosition(window).x <= 760 + (925 - 760) * 2 + (760 - 685) * 2 &&
                Mouse::getPosition(window).y >= 420 &&
                Mouse::getPosition(window).y <= 490;
            mouse_position_is_inside_first_color_option_in_change_color_page =
                Mouse::getPosition(window).x >= 770 &&
                Mouse::getPosition(window).x <= 845 &&
                Mouse::getPosition(window).y >= 600 &&
                Mouse::getPosition(window).y <= 640;
            mouse_position_is_inside_second_color_option_in_change_color_page =
                Mouse::getPosition(window).x >= 845 + (1055 - 845) &&
                Mouse::getPosition(window).x <= 845 + (1055 - 845) + (845 - 770) &&
                Mouse::getPosition(window).y >= 600 &&
                Mouse::getPosition(window).y <= 640;
        }
        if (left_or_right_mouse_button_pressed && check.is_change_snake_button_pressed && !check.is_audio_button_pressed &&
            !check.is_game_button_pressed && !check.is_ranking_button_pressed && !check.is_setting_button_pressed) {
            if (mouse_position_is_inside_Exit_in_change_color_page)
            {
                check.is_setting_button_pressed = 1;
                check.is_change_snake_button_pressed = 0;
            }
            if (mouse_position_is_inside_first_snake_in_change_color_page)
            {
                check.is_snake_1_being_used = 1;
                check.is_snake_2_being_used = 0;
                check.is_snake_3_being_used = 0;
                check.is_snake_4_being_used = 0;
            }
            else if (mouse_position_is_inside_second_snake_in_change_color_page)
            {
                check.is_snake_1_being_used = 0;
                check.is_snake_2_being_used = 1;
                check.is_snake_3_being_used = 0;
                check.is_snake_4_being_used = 0;
            }
            else if (mouse_position_is_inside_third_snake_in_change_color_page)
            {
                check.is_snake_1_being_used = 0;
                check.is_snake_2_being_used = 0;
                check.is_snake_3_being_used = 1;
                check.is_snake_4_being_used = 0;
            }
            else if (mouse_position_is_inside_forth_snake_in_change_color_page)
            {
                check.is_snake_1_being_used = 0;
                check.is_snake_2_being_used = 0;
                check.is_snake_3_being_used = 0;
                check.is_snake_4_being_used = 1;
            }
            if (mouse_position_is_inside_first_color_option_in_change_color_page)
            {
                check.is_snake_changing_colors = 1;
            }
            else if (mouse_position_is_inside_second_color_option_in_change_color_page)
            {
                check.is_snake_changing_colors = 0;
            }

        }
    }
    collision_counter++;
}

void update_game(shape& shapes, int& game_counter, Check& check, int number_of_eaten_apples) {
    //the time it will take the snake to change positions which will make it move faster
    int speedtimer = snake_size_and_speed * 0.25;
    if (check.is_resize_button_pressed) {
        speedtimer *= 1.5;
    }
    //the time it will take the apple to change positions
    int apple_timer = 6 * 50;
    //the time it will take the rotten apple to change positions
    int rotten_apple_timer = apple_timer * 2;

    //the higher the numofapples the lower it take the apple,rotten apple,and snake to change positions
    if (number_of_eaten_apples >= 60) {
        speedtimer *= 0.25;
        apple_timer *= 0.25;
        rotten_apple_timer *= 0.25;
    }
    else if (number_of_eaten_apples >= 40) {
        speedtimer *= 0.5;
        apple_timer *= 0.5;
        rotten_apple_timer *= 0.5;
    }
    else if (number_of_eaten_apples >= 20) {
        speedtimer *= 0.75;
        apple_timer *= 0.75;
        rotten_apple_timer *= 0.75;
    }

    if (game_counter % speedtimer == 0)
        snake_movement(check);

    if (game_counter % apple_timer == 0)
        randapple(shapes, check, number_of_eaten_apples);
    if ((game_counter % rotten_apple_timer == 0))
        randrottenapple(shapes, check, number_of_eaten_apples);
    game_counter++;

}

//use check move
/*to change the direction of the snake when the player presses w / s / a / d or the arrow buttons and it will keep moving
in the same direction as the last button pressed */
void snake_movement(Check& check) {
    bool is_d_or_right_key_pressed = Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right);
    bool is_a_or_left_key_pressed = Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left);
    bool is_s_or_down_key_pressed = Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down);
    bool is_w_or_up_key_pressed = Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up);

    bool snake_isnt_going_left = speed[0][0] != (-1 * snake_size_and_speed);
    bool snake_isnt_going_right = speed[0][0] != snake_size_and_speed;
    bool snake_isnt_going_up = speed[0][1] != -1 * snake_size_and_speed;
    bool snake_isnt_going_down = speed[0][1] != snake_size_and_speed;

    if (is_d_or_right_key_pressed && snake_isnt_going_left) {
        speed[0][0] = snake_size_and_speed; speed[0][1] = 0;
        changexny();
        check.if_the_player_started_playing = 1;
    }
    else if (is_a_or_left_key_pressed && snake_isnt_going_right) {
        speed[0][0] = -1 * snake_size_and_speed; speed[0][1] = 0;
        changexny();
        check.if_the_player_started_playing = 1;
    }
    else if (is_s_or_down_key_pressed && snake_isnt_going_up)
    {
        speed[0][0] = 0; speed[0][1] = snake_size_and_speed;
        changexny();
        check.if_the_player_started_playing = 1;
    }
    else if (is_w_or_up_key_pressed && snake_isnt_going_down)
    {
        speed[0][0] = 0; speed[0][1] = -1 * snake_size_and_speed;
        changexny();
        check.if_the_player_started_playing = 1;
    }
    else {
        if (check.if_the_player_started_playing)
            changexny();

    }
}


//to make sure that all squares moved in their direction and then passed that direction to the next square
void changexny() {
    for (int i = 0; i < MAX_NUMBER_OF_SQUARES; i++) {
        snake[i].move(speed[i][0], speed[i][1]);
    }
    for (int i = MAX_NUMBER_OF_SQUARES - 1; i >= 1; i--) {
        speed[i][0] = speed[i - 1][0];
        speed[i][1] = speed[i - 1][1];
    }
}

//use check apple and collided
//to draw everything in the game
void draw_game(shape& shapes, int& number_of_eaten_apples, Check& check, Font font, shapetextures textures) {

    window.clear(Color(0, 29, 0, 233));
    //Background
    window.draw(game_background);

    //to check if the apple was eaten
    if (check.is_the_apple_eaten == 0) {
        window.draw(shapes.apple_icon);
    }

    if (check.is_the_rotten_apple_eaten == 0 && number_of_eaten_apples > 0) {
        window.draw(shapes.rotten_apple_icon);
    }
    set_texture(number_of_eaten_apples, check, textures);
    for (int square_number = 0; square_number < number_of_eaten_apples + 3; square_number++) {
        set_color(square_number, number_of_eaten_apples, check);
        if (check.is_snake_1_being_used)
            set_rotation(number_of_eaten_apples, square_number);

        window.draw(snake[square_number]);

    }
    apple_counter(number_of_eaten_apples, check);
    if (check.is_the_setting_in_game_button_pressed && check.is_the_snake_alive) {
        draw_resume_icon(shapes, check);
        draw_restart_icon(shapes, check);
        draw_exit_icon(shapes, check);

    }
    if (!check.is_the_snake_alive) {
        if (check.is_resize_button_pressed) {
            shapes.game_over.setPosition(800, 100);
        }
        else
            shapes.game_over.setPosition(500, 50);
        window.draw(shapes.game_over);
        draw_restart_icon(shapes, check);
        draw_exit_icon(shapes, check);
    }
    window.display();

}

void set_texture(int number_of_eaten_apples, Check check, shapetextures& textures) {

    textures.snake_turn_texture = &textures.snaketurntexture;
    textures.snake_body_texture = &textures.snakebodytexture;
    textures.snake_tail_texture = &textures.snaketailtexture;
    textures.snake_head_texture = &textures.snakeheadtexture;
    if (check.is_snake_1_being_used) {

        for (int i = 0; i < number_of_eaten_apples + 3; i++) {
            bool is_snake_turn = speed[i][0] == speed[i + 1][1] || speed[i][0] == -speed[i + 1]
                [1] || speed[i][1] == speed[i + 1][0] || speed[i][1] == -speed[i + 1][0];
            if (i == 0)
                snake[i].setTexture(textures.snake_head_texture);
            else if (is_snake_turn)
                snake[i].setTexture(textures.snake_turn_texture);
            else if (i == number_of_eaten_apples + 2) {
                snake[i].setTexture(textures.snake_tail_texture);
            }
            else {
                snake[i].setTexture(textures.snake_body_texture);
            }
        }
    }
    else if (check.is_snake_2_being_used) {
        for (int i = 0; i < number_of_eaten_apples + 3; i++) {
            snake[i].setRotation(0);
            if (i == 0)
            {
                if (speed[i][0] == snake_size_and_speed) {
                    snake[i].setTexture(head_right_texture1);
                }
                else if (speed[i][0] == -snake_size_and_speed) {
                    snake[i].setTexture(head_left_texture1);
                }
                else if (speed[i][1] == snake_size_and_speed) {
                    snake[i].setTexture(head_down_texture1);
                }
                else if (speed[i][1] == -snake_size_and_speed) {
                    snake[i].setTexture(head_up_texture1);
                }
            }
            else if (i == number_of_eaten_apples + 2)
            {

                if (speed[i][1] == -snake_size_and_speed) {
                    snake[i].setTexture(tail_down_texture1);
                }
                else if (speed[i][1] == snake_size_and_speed) {
                    snake[i].setTexture(tail_up_texture1);
                }
                else if (speed[i][0] == snake_size_and_speed) {
                    snake[i].setTexture(tail_left_texture1);
                }
                else if (speed[i][0] == -snake_size_and_speed) {
                    snake[i].setTexture(tail_right_texture1);
                }

            }
            else
            {
                if ((speed[i + 1][0] == snake_size_and_speed && speed[i][1] == -snake_size_and_speed) ||
                    (speed[i + 1][1] == snake_size_and_speed && speed[i][0] == -snake_size_and_speed)) {
                    snake[i].setTexture(body_topleft_texture1);
                }
                else if ((speed[i + 1][0] == snake_size_and_speed && speed[i][1] == snake_size_and_speed) ||
                    (speed[i + 1][1] == -snake_size_and_speed && speed[i][0] == -snake_size_and_speed)) {
                    snake[i].setTexture(body_bottomleft_texture1);
                }
                else if ((speed[i + 1][1] == snake_size_and_speed && speed[i][0] == snake_size_and_speed) ||
                    (speed[i + 1][0] == -snake_size_and_speed && speed[i][1] == -snake_size_and_speed)) {
                    snake[i].setTexture(body_topright_texture1);
                }
                else if ((speed[i + 1][1] == -snake_size_and_speed && speed[i][0] == snake_size_and_speed) ||
                    (speed[i + 1][0] == -snake_size_and_speed && speed[i][1] == snake_size_and_speed)) {
                    snake[i].setTexture(body_bottomright_texture1);
                }

                else if (speed[i][0] == snake_size_and_speed) {
                    snake[i].setTexture(body_horizontal_texture1);
                }
                else if (speed[i][0] == -snake_size_and_speed) {
                    snake[i].setTexture(body_horizontal_texture1);
                }
                else if (speed[i][1] == snake_size_and_speed) {
                    snake[i].setTexture(body_vertical_texture1);
                }
                else if (speed[i][1] == -snake_size_and_speed) {
                    snake[i].setTexture(body_vertical_texture1);
                }


            }
        }
    }
    else if (check.is_snake_3_being_used) {
        for (int i = 0; i < number_of_eaten_apples + 3; i++) {
            snake[i].setTexture(NULL);
        }
    }
    else if (check.is_snake_4_being_used)
    {
        for (int i = 0; i < number_of_eaten_apples + 3; i++) {
            snake[i].setRotation(0);
            if (i == 0)
            {
                snake[i].setTexture(head_right_texture2);
                if (speed[i][0] == snake_size_and_speed) {

                }
                else if (speed[i][0] == -snake_size_and_speed) {
                    snake[i].setRotation(180);
                }
                else if (speed[i][1] == snake_size_and_speed) {
                    snake[i].setRotation(90);
                }
                else if (speed[i][1] == -snake_size_and_speed) {
                    snake[i].setRotation(270);
                }
            }
            else if (i == number_of_eaten_apples + 2)
            {
                snake[i].setTexture(tail_left_texture2);
                if (speed[i][1] == -snake_size_and_speed) {
                    snake[i].setRotation(270);
                }
                else if (speed[i][1] == snake_size_and_speed) {
                    snake[i].setRotation(90);
                }
                else if (speed[i][0] == snake_size_and_speed) {

                }
                else if (speed[i][0] == -snake_size_and_speed) {
                    snake[i].setRotation(180);
                }

            }
            else
            {
                if ((speed[i + 1][0] == snake_size_and_speed && speed[i][1] == -snake_size_and_speed) ||
                    (speed[i + 1][1] == snake_size_and_speed && speed[i][0] == -snake_size_and_speed)) {
                    snake[i].setTexture(body_topright_texture2);
                    snake[i].setRotation(270);

                }
                else if ((speed[i + 1][0] == snake_size_and_speed && speed[i][1] == snake_size_and_speed) ||
                    (speed[i + 1][1] == -snake_size_and_speed && speed[i][0] == -snake_size_and_speed)) {
                    snake[i].setTexture(body_topright_texture2);
                    snake[i].setRotation(180);
                    
                }
                else if ((speed[i + 1][1] == snake_size_and_speed && speed[i][0] == snake_size_and_speed) ||
                    (speed[i + 1][0] == -snake_size_and_speed && speed[i][1] == -snake_size_and_speed)) {
                    snake[i].setTexture(body_topright_texture2);
                    
                }
                else if ((speed[i + 1][1] == -snake_size_and_speed && speed[i][0] == snake_size_and_speed) ||
                    (speed[i + 1][0] == -snake_size_and_speed && speed[i][1] == snake_size_and_speed)) {
                    snake[i].setTexture(body_topright_texture2);
                    snake[i].setRotation(90);
                }

                else if (speed[i][0] == snake_size_and_speed) {
                    snake[i].setTexture(body_horizontal_texture2);
                }
                else if (speed[i][0] == -snake_size_and_speed) {
                    snake[i].setTexture(body_horizontal_texture2);
                }
                else if (speed[i][1] == snake_size_and_speed) {
                    snake[i].setTexture(body_horizontal_texture2);
                    snake[i].setRotation(90);

                }
                else if (speed[i][1] == -snake_size_and_speed) {
                    snake[i].setTexture(body_horizontal_texture2);
                    snake[i].setRotation(90);

                }


            }
        }
    }
}

//to change colors of the snake with every key pressed and to change the angle of the rotation of each square based on their direction
void set_color(int square_number, int number_of_eaten_apples, Check check) {
    if (check.is_snake_changing_colors) {
        if (number_of_eaten_apples < 20) {
            if (speed[0][0] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Magenta);
                else
                    snake[square_number].setFillColor(Color::White);
            }
            else if (speed[0][0] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Green);
                else
                    snake[square_number].setFillColor(Color::Blue);
            }
            else if (speed[0][1] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::White);
                else
                    snake[square_number].setFillColor(Color::Red);
            }
            else if (speed[0][1] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Cyan);
                else
                    snake[square_number].setFillColor(Color::Red);
            }
        }
        else if (number_of_eaten_apples >= 20 && number_of_eaten_apples < 40) {
            if (speed[0][0] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::White);
                else
                    snake[square_number].setFillColor(Color::Magenta);
            }
            else if (speed[0][0] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Black);
                else
                    snake[square_number].setFillColor(Color::Cyan);
            }
            else if (speed[0][1] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Cyan);
                else
                    snake[square_number].setFillColor(Color::Blue);
            }
            else if (speed[0][1] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Black);
                else
                    snake[square_number].setFillColor(Color::Red);
            }
        }
        else if (number_of_eaten_apples >= 40 && number_of_eaten_apples < 60) {
            if (speed[0][0] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Red);
                else
                    snake[square_number].setFillColor(Color::Magenta);
            }
            else if (speed[0][0] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Black);
                else
                    snake[square_number].setFillColor(Color::White);
            }
            else if (speed[0][1] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Cyan);
                else
                    snake[square_number].setFillColor(Color::Green);
            }
            else if (speed[0][1] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Blue);
                else
                    snake[square_number].setFillColor(Color::Red);
            }
        }
        else {
            if (speed[0][0] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Green);
                else
                    snake[square_number].setFillColor(Color::Magenta);
            }
            else if (speed[0][0] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Magenta);
                else
                    snake[square_number].setFillColor(Color::Cyan);
            }
            else if (speed[0][1] == snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Cyan);
                else
                    snake[square_number].setFillColor(Color::White);
            }
            else if (speed[0][1] == -1 * snake_size_and_speed) {
                if (square_number % 2 == 0)
                    snake[square_number].setFillColor(Color::Black);
                else
                    snake[square_number].setFillColor(Color::Blue);
            }
        }
    }
    else {
        if (number_of_eaten_apples < 20) {

            snake[square_number].setFillColor(Color::Green);
        }
        else if (number_of_eaten_apples >= 20 && number_of_eaten_apples < 40) {

            snake[square_number].setFillColor(Color::Blue);
        }
        else if (number_of_eaten_apples >= 40 && number_of_eaten_apples < 60) {
            snake[square_number].setFillColor(Color::Red);
        }
        else {
            snake[square_number].setFillColor(Color::Black);
        }

    }
}

void set_rotation(int number_of_eaten_apples, int square_number) {

    bool is_snake_turn = (speed[square_number][0] == speed[square_number + 1][1] || speed[square_number][0] == -speed[square_number + 1][1] ||
        speed[square_number][1] == speed[square_number + 1][0] || speed[square_number][1] == -speed[square_number + 1][0]);

    bool is_this_square_going_right = speed[square_number][0] == snake_size_and_speed;
    bool is_this_square_going_left = speed[square_number][0] == -snake_size_and_speed;
    bool is_this_square_going_upward = speed[square_number][1] == -snake_size_and_speed;
    bool is_this_square_going_downward = speed[square_number][1] == snake_size_and_speed;

    bool is_the_next_square_going_right = speed[square_number + 1][0] == snake_size_and_speed;
    bool is_the_next_square_going_left = speed[square_number + 1][0] == -snake_size_and_speed;
    bool is_the_next_square_going_upward = speed[square_number + 1][1] == -snake_size_and_speed;
    bool is_the_next_square_going_downward = speed[square_number + 1][1] == snake_size_and_speed;

    if (square_number != (number_of_eaten_apples + 2) || is_snake_turn) {
        if (is_snake_turn && square_number != 0) {

            if ((is_the_next_square_going_right && is_this_square_going_upward) ||
                (is_the_next_square_going_downward && is_this_square_going_left)) {
                snake[square_number].setRotation(180);
            }

            else if ((is_the_next_square_going_right && is_this_square_going_downward) ||
                (is_the_next_square_going_upward && is_this_square_going_left)) {

                snake[square_number].setRotation(90);
            }

            else if ((is_the_next_square_going_downward && is_this_square_going_right) ||
                (is_the_next_square_going_left && is_this_square_going_upward)) {

                snake[square_number].setRotation(270);
            }

            else if ((is_the_next_square_going_upward && is_this_square_going_right) ||
                (is_the_next_square_going_left && is_this_square_going_downward)) {

                snake[square_number].setRotation(0);
            }
        }
        else {
            if (is_this_square_going_right) {
                snake[square_number].setRotation(270);
            }
            else if (is_this_square_going_left) {
                snake[square_number].setRotation(90);
            }
            else if (is_this_square_going_downward)
                snake[square_number].setRotation(0);
            else if (is_this_square_going_upward)
                snake[square_number].setRotation(180);
        }
    }
    else {
        if (is_this_square_going_right)
            snake[square_number].setRotation(90);
        else if (is_this_square_going_left)
            snake[square_number].setRotation(270);
        else if (is_this_square_going_downward)
            snake[square_number].setRotation(180);
        else if (is_this_square_going_upward)
            snake[square_number].setRotation(0);
    }

}

//to create score counter
void apple_counter(int number_of_eaten_apples, Check check) {
    // Display score
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(30);
    text.setPosition(70, 20);
    if (check.is_resize_button_pressed) {
        text.setCharacterSize(40);
        text.setPosition(85, 25);
    }
    text.setString("Score: " + std::to_string(number_of_eaten_apples));
    window.draw(text);
}

//use check apple
//to change the position of the apple 
void randapple(shape& shapes, Check& check, int number_of_eaten_apples) {
    shapes.apple_icon.setPosition(Vector2f(rand() % ((1707 - 213) - (int)snake_size_and_speed) + 213, rand() %
        ((982 - 95) - (int)snake_size_and_speed) + 95));
    //to make sure that the apple do not appear on the snake body
    for (int i = 0; i < number_of_eaten_apples + 2; i++) {
        if (snake[i].getGlobalBounds().intersects(shapes.apple_icon.getGlobalBounds()) || shapes.apple_icon.getGlobalBounds().
            intersects(shapes.rotten_apple_icon.getGlobalBounds())) {
            shapes.apple_icon.setPosition(Vector2f(rand() % ((1707 - 213) - (int)snake_size_and_speed) + 213, rand() %
                ((982 - 95) - (int)snake_size_and_speed) + 95));
            i = 0;
        }
    }
    shapes.apple_icon.setRadius(snake_size_and_speed * 0.5);
    check.is_the_apple_eaten = 0;
}

//to change the position of rotten apple
void randrottenapple(shape& shapes, Check& check, int number_of_eaten_apples) {
    shapes.rotten_apple_icon.setPosition(Vector2f(rand() % ((1707 - 213) - (int)snake_size_and_speed) + 213, rand() %
        ((982 - 95) - (int)snake_size_and_speed) + 95));
    //to make sure that the rotten apple do not appear on the snake body
    for (int i = 0; i < number_of_eaten_apples + 2; i++) {
        if (snake[i].getGlobalBounds().intersects(shapes.rotten_apple_icon.getGlobalBounds()) || shapes.rotten_apple_icon.
            getGlobalBounds().intersects(shapes.apple_icon.getGlobalBounds())) {
            shapes.rotten_apple_icon.setPosition(Vector2f(rand() % ((1707 - 213) - (int)snake_size_and_speed) + 213, rand() %
                ((982 - 95) - (int)snake_size_and_speed) + 95));
            i = 0;
        }
    }
    shapes.rotten_apple_icon.setRadius(snake_size_and_speed);
    check.is_the_rotten_apple_eaten = 0;
}

//o draw the pause button
void draw_resume_icon(shape shapes, Check check) {
    shapes.resume_icon.setFillColor(Color::White);
    shapes.resume_icon.setSize(Vector2f(250, 200));
    shapes.resume_icon.setPosition(550, 200);
    if (check.is_resize_button_pressed) {
        shapes.resume_icon.setPosition(800, 300);
    }
    window.draw(shapes.resume_icon);
}

void draw_restart_icon(shape shapes, Check check) {
    if (check.is_the_snake_alive == 0)
        if (check.is_resize_button_pressed)
            shapes.restart_icon.setPosition(600, 400);
        else
            shapes.restart_icon.setPosition(400, 300);
    else
        if (check.is_resize_button_pressed)
            shapes.restart_icon.setPosition(800, 400);
        else
            shapes.restart_icon.setPosition(550, 300);
    shapes.restart_icon.setSize(Vector2f(250, 200));
    shapes.restart_icon.setFillColor(Color::White);
    window.draw(shapes.restart_icon);
}

void draw_exit_icon(shape shapes, Check check) {
    if (check.is_the_snake_alive == 0)
        if (check.is_resize_button_pressed)
            shapes.exit_icon.setPosition(1000, 400);
        else
            shapes.exit_icon.setPosition(630, 300);
    else
        if (check.is_resize_button_pressed)
            shapes.exit_icon.setPosition(800, 500);
        else
            shapes.exit_icon.setPosition(550, 400);
    shapes.exit_icon.setSize(Vector2f(250, 200));
    shapes.exit_icon.setFillColor(Color::White);
    window.draw(shapes.exit_icon);
}

void drawMainMenu(Font& font, shape shapes, Check check)
{
    // create the "Start" button
    window.clear(Color(0, 29, 0, 233));

    window.draw(shapes.main_menu_page);
    //Background
    Text startButton;
    startButton.setFont(font);
    startButton.setString("Start");
    startButton.setFillColor(Color::White);


    // create the "View High Score" button
    Text highScoreButton;
    highScoreButton.setFont(font);
    highScoreButton.setString("High Score");
    highScoreButton.setFillColor(Color::White);

    // create the "Exit" button
    Text exitButton;
    exitButton.setFont(font);
    exitButton.setString("Exit");
    exitButton.setFillColor(Color::White);


    if (check.is_resize_button_pressed) {
        startButton.setCharacterSize(40);
        startButton.setPosition(Vector2f((window.getSize().x / 2 - 45), (window.getSize().y / 2 + 75)));

        highScoreButton.setCharacterSize(37);
        highScoreButton.setPosition(Vector2f(window.getSize().x / 2 - 90, window.getSize().y / 2 + 205));

        exitButton.setCharacterSize(40);
        exitButton.setPosition(Vector2f(window.getSize().x / 2 - 35, window.getSize().y / 2 + 335));
    }
    else {
        startButton.setCharacterSize(32);
        startButton.setPosition(Vector2f((window.getSize().x / 2 - 35), (window.getSize().y / 2 + 50)));

        highScoreButton.setCharacterSize(29);
        highScoreButton.setPosition(Vector2f(window.getSize().x / 2 - 75, window.getSize().y / 2 + 150));

        exitButton.setCharacterSize(32);
        exitButton.setPosition(Vector2f(window.getSize().x / 2 - 25, window.getSize().y / 2 + 245));
    }
    window.draw(startButton);
    window.draw(highScoreButton);
    window.draw(exitButton);
    window.display();
}

void drawSettingsMenu(Font& font, shape shapes, Check check)
{
    // Background
    window.clear(Color(0, 29, 0, 233));
    window.draw(shapes.setting_page);
    // create the "Audio" button
    Text audioButton;
    audioButton.setFont(font);
    audioButton.setString("Audio");
    audioButton.setFillColor(Color::White);
    audioButton.setCharacterSize(32);
    audioButton.setPosition(Vector2f(window.getSize().x / 2 - 40, window.getSize().y / 2 - 75));

    // create the "fullScreen" button
    Text change_snake_button;
    change_snake_button.setFont(font);
    change_snake_button.setString("Change snake");
    change_snake_button.setFillColor(Color::White);
    change_snake_button.setCharacterSize(32);
    change_snake_button.setPosition(Vector2f(window.getSize().x / 2 - 100, window.getSize().y / 2 + 20));


    // create the "Back" button
    Text backButton;
    backButton.setFont(font);
    backButton.setString("Back");
    backButton.setFillColor(Color::White);
    backButton.setCharacterSize(32);
    backButton.setPosition(Vector2f(window.getSize().x / 2 - 30, window.getSize().y / 2 + 120));
    if (check.is_resize_button_pressed) {
        audioButton.setCharacterSize(40);
        audioButton.setPosition(Vector2f(window.getSize().x / 2 - 50, window.getSize().y / 2 - 100));

        change_snake_button.setCharacterSize(40);
        change_snake_button.setPosition(Vector2f(window.getSize().x / 2 - 110, window.getSize().y / 2 + 30));

        backButton.setCharacterSize(40);
        backButton.setPosition(Vector2f(window.getSize().x / 2 - 30, window.getSize().y / 2 + 160));
    }


    window.draw(audioButton);
    window.draw(change_snake_button);
    window.draw(backButton);
    window.display();
}

void draw_view_high_score_menu(shape shapes, Text text, int ranking[], Check check)
{
    window.clear();
    window.draw(shapes.ranking_page);
    string number;
    text.setCharacterSize(32);
    if (check.is_resize_button_pressed) {
        text.setCharacterSize(40);

    }
    text.setStyle(Text::Bold);
    for (int q = 0; q < 3; q++) {
        int u = 1000;

        for (int i = 0; i < 4; i++) {
            if (i > 0)
                u = u / 10;
            number = '0' + ((ranking[q] / u) % 10);
            text.setString(number);
            text.setPosition(Vector2f(725 + (20 * i), 340 + 100 * q));
            if (check.is_resize_button_pressed) {
                text.setPosition(Vector2f(1060 + (30 * i), 470 + 130 * q));
            }
            window.draw(text);
        }
    }

    window.display();

}

void changing_ranking(int number_of_eaten_apples, int ranking[])
{

    int swipe;

    for (int i = 0; i < 3; i++)
    {
        if (ranking[i] < number_of_eaten_apples)
        {
            swipe = ranking[i];
            ranking[i] = number_of_eaten_apples;
            if (i == 0) {
                swap(ranking[1], ranking[2]);
                ranking[1] = swipe;
            }
            else if (i == 1) {
                swap(ranking[2], swipe);
            }
            break;
        }

    }

}

void draw_audio_settings(shape shapes, Check check) {
    window.clear();
    window.draw(shapes.setting_music_page);
    shapes.exit_icon_in_setting_music_page.setPosition(Vector2f(780, 200));
    if (check.is_resize_button_pressed)
        shapes.exit_icon_in_setting_music_page.setPosition(Vector2f(1100, 250));
    window.draw(shapes.exit_icon_in_setting_music_page);
    window.display();
}

void draw_change_color(shape shapes, Check& check)
{
    window.clear();
    window.draw(shapes.change_snake_page);
    if (check.is_resize_button_pressed) {
        if (check.is_snake_1_being_used)
        {
            shapes.Tru_ee.setPosition(570, 330);
        }
        else if (check.is_snake_2_being_used)
        {
            shapes.Tru_ee.setPosition(810, 330);
        }
        else if (check.is_snake_3_being_used)
        {
            shapes.Tru_ee.setPosition(1050, 330);
        }
        window.draw(shapes.Tru_ee);
        if (check.is_snake_changing_colors)
        {
            shapes.Tru_ee.setPosition(655, 495);

        }
        else
        {
            shapes.Tru_ee.setPosition(940, 495);

        }
        window.draw(shapes.Tru_ee);
    }
    else {
        if (check.is_snake_1_being_used)
        {
            shapes.Tru_ee.setPosition(505, 223);
        }
        else if (check.is_snake_2_being_used)
        {
            shapes.Tru_ee.setPosition(313, 223);
        }
        else if (check.is_snake_3_being_used)
        {
            shapes.Tru_ee.setPosition(697, 223);
        }
        else if (check.is_snake_4_being_used)
        {
            shapes.Tru_ee.setPosition(409, 223);
        }
        window.draw(shapes.Tru_ee);
        if (check.is_snake_changing_colors)
        {
            shapes.Tru_ee.setPosition(397, 387);

        }
        else
        {
            shapes.Tru_ee.setPosition(563, 387);

        }
        window.draw(shapes.Tru_ee);
    }
    window.display();

}
