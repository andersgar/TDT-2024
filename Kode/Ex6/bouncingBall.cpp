#include "bouncingBall.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800};
constexpr int BOUNCE_WINDOW_HEIGHT{500};

istream &operator>>(istream &is, Config &cfg)
{
    is >> cfg.colorUp >> cfg.colorDown >> cfg.speed;
    return is;
}

pair<Config, Config> getConfigValues()
{
    filesystem::path configFile{"bouncingBallConfig.txt"};
    ifstream configIs{configFile}; // Define input stream from config file

    if (!configIs)
    {
        cout << "Could not open file " << configFile << "!" << endl;
        return make_pair(Config{}, Config{}); // Returns empty Config variables
    }
    Config slow, fast;            // Define two variables of Config type;
    configIs >> slow >> fast;     // Get variables from file, for each time the >> operator is used, the program advances to the next line.
    return make_pair(slow, fast); // Returns as a pair
}

void bouncingBall()
{
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y,
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};

    const int radius = 30;
    int angle = 1;
    int x{0}, y{360}, increment_x{0}, increment_y{0};
    int count_bounce_top{0}, count_bounce_bottom{0}, count_num_passes{0};

    int velocity;
    Color colorUp, colorDown;
    auto [slow, fast] = getConfigValues(); // Read from config file

    //* Init
    Config currentConfig = slow;
    velocity = currentConfig.speed;
    colorUp = colorMap.at(currentConfig.colorUp);
    colorDown = colorMap.at(currentConfig.colorDown);

    while (!window.should_close())
    {
        // Determine increments based on the velocity
        increment_x = velocity * cos(angle);
        increment_y = velocity * sin(angle);

        //* Movement in x-direction
        if ((increment_x + x) > window.width())
        {
            x = 0;              // reached right side - wrap around to the leftmost
            count_num_passes++; // increment counter which counts number of full left-to-right passes

            if (count_num_passes % 5 == 0) // alternate between slow and fast configuration every fifth pass
            {
                currentConfig = (currentConfig == slow) ? fast : slow; // Change configuration, ternary operator

                // update both velcity and colors
                velocity = currentConfig.speed;
                colorUp = colorMap.at(currentConfig.colorUp);
                colorDown = colorMap.at(currentConfig.colorDown);
            }
        }
        else
        {
            x += increment_x; // moving rightwards
        }

        //* Movement in y-direction
        if (((count_bounce_top + count_bounce_bottom) % 2) == 0)
        {
            // Move upwards
            if (y + increment_y + radius >= window.height())
            { // Hit top of window, turn around
                increment_y = -increment_y;
                count_bounce_top++;
            }
            else
            {
                y += increment_y;
                window.draw_circle({x, y}, radius, colorUp);
            }
        }
        else
        {
            // Move downward
            if (y + increment_y - radius <= 0)
            { // Hit bottom of window, turn around
                increment_y = -increment_y;
                count_bounce_bottom++;
            }
            else
            {
                y -= increment_y;
                window.draw_circle({x, y}, radius, colorDown);
            }
        }
        window.next_frame();
    }
}