{ //Inside the 'while (pollEvent())' scope or something else.
  static bool lock_click; // Create a bool variable for locking the click.
  if (evnt.type == sf::Event::MouseButtonPressed) //Mouse button Pressed
  {
      if (evnt.mouseButton.button == sf::Mouse::Left && lock_click != true) //specifies
      {
          /* your code here*/
          std::cout << "lmb-pressed" << std::endl; // usually this will show in a  loop because is being pressed;
          lock_click = true; //And now, after all your code, this will lock the loop and not print "lmb" in a x held time. 
          /* or here idk */
      }   
  }

  if (evnt.type == sf::Event::MouseButtonReleased) //Mouse button Released now.
  {
      if (evnt.mouseButton.button == sf::Mouse::Left) //specifies the held button       again. (You can make a variable for that if you want)
      {
          lock_click = false; //unlock when the button has been released.
      }
  } //Released Scope
}