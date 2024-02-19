#ifndef BALL_H
#define BALL_H
/**
   This class models a ball that bounces off walls.
*/
class Ball
{
public:
   /**
      Constructs a ball at (0, 0) traveling northeast.
      @param right_wall the position of the wall to the right
      @param top_wall the position of the wall at the top
   */
   Ball(int right_wall, int top_wall);

   /**
      Moves the ball.
   */
   void move();

   /**
      Turns the ball direction 90 degrees clockwise.
   */
   void turn();

   /**
      Gets the current x-position.
      @return the x-position
   */
   int get_x() const;

   /**
      Gets the current y-position.
      @return the y-position
   */
   int get_y() const;

private:
   int x;
   int y;
   int dx; 
   int dy;
   int max_x;
   int max_y;
};

#endif