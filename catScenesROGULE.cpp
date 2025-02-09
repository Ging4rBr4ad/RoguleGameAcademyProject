#include "classLibROGULE.h"

void Scene(short& level, std::string& name, Item inventory[], int& InvSize)
{
    if(level == 0)
    {
        system("cls");

        std::cout << "You are - a brave hero. You are going to go on a\n"
                "journey to find the most valuable thing in the world.\n"
                "Your way will be very dangerous and full of monsters,\n"
                "new meetings and beautiful landscapes.\n\n"
                "Everyone will know your name - hero .....\n\n"
                "By the way, what is your name?\n\n"
                "\"My name is \"";
        std::cin >> name;
        system("cls");

        std::cout << "Everyone will know your name - hero " << name << "\n\n"
                "After preparation, " << name << " started his/her journey.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");
    }
    else if (level == 1)
    {
        std::cout << name << "'s journey sterted in very spooky place - \n"
                        "Echo swamps. Lots of spirits and ghosts wander\n"
                        "here. They look for rest in peace and howl nosily.\n"
                        "Travelers think that swamps are alive.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "But " << name << " is not scared at all! Simple ghosts\n"
                    "can't bit him/her.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << name << " was walking his/her way, when he/she heard\n"
                    "a strange sound under his/her legs. " << name << "\n"
                    "looked down and then hundreds of vines and leaves tied\n"
                    << name << " up. " << name << " tried to cut it with his/her\n"
                    "sword but vines took it off. After that an old wizard came\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "\"Why are you trampling my seedlings?!\" - asked wizard.\n"
                << name << " was confused. - \"I didn't noticed it! I'm very sorry!\"\n"
                "The wizard was looking at " << name << " suspiciously for a few seconds.\n"
                "He still was mad at " << name << " but then he helped him/her to\n"
                "free himself/herself.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "Wizard set " << name << " down on the bench next to\n"
                    "seedlings.\n"
                    "\"What are you doing on Echo swamps?\" - he asked and\n"
                    << name << " tell him about his/her journey. The wizard\n"
                    "was not surprised.\n"
                    "\"My name is Osman and I'm the great wizard! I live here\n"
                    "whole my life. And you are just a traveler. Are you sure\n"
                    "that you'd like to continue your journey?\"\n"
                    << name << " was absoulutely sure.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "Realizing that " << name << " couldn't be persuaded,\n"
                    "Osman sighed and offerd his help to " << name << ".\n"
                    "\"Take this artifact.\" - said Osman and gave " << name << "\n"
                    "a beautiful talisman. \"You can save up your magic power\n"
                    "in it and then let it out. It will help you in you travel.\"\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        Choice(level, name, inventory, InvSize);

        std::cout << "And then " << name << " continued the journey.\n"
                << name << " went to Echo swamps\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");
    }   
    else if(level == 2)
    {
        std::cout << "After dark dirty swamps " << name << "came to the\n"
                    "beautiful meadow. Here was shiny and nice. Adorable\n"
                    "flowers were there. Air was clean and fresh.\n"
                    << name << " felt so light in this wonderful place!\n\n"
                    "( Your power, defence and HP increases )\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << name << " felt how his/her inner child was going out.\n"
                << name << " started to run throw the beautiful landscapes,\n"
                "looking around. He/she smelled nice aromas of flowers.\n"
                "Then he/she fell on the green grass and looked up.\n"
                << name << " was looking at clouds before he/she fell asleep.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << name << "'s sleep was interrupted by a sheep, wich\n"
                "decided that " << name << "'s hair is a very delicious\n"
                "grass.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "\"Oh! I'm sorry, dear traveler!\" - said the\n"
                    "young cute shepherdess. " << name << " set on the\n"
                    "grass and looked around. There were lots of sheep.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "\"My name is Dorothy\" - said the shepherdess. -\n"
                    "\"My sheep woke you up. I'm so sorry!\"\n"
                    "\"That is OK!\" - said " << name << ".\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << name << " introduced himself/herself amd stood up.\n"
                "\"Where did you come from?\" - ascked Dorothy. Then\n"
                << name << " told about the journey and Echo swamps.\n"
                "Dorothy was so amused of " << name << "'s story so\n"
                << name << " couldn't resist and embellished his/her\n"
                "story a little.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "\"And where are you gonna go now?\" - asked\n"
                    "little shepherdess. \"I have to go throgh the\n"
                    "Curly garden!\" - said " << name << ".\n"
                    "Dorothy looked at " << name << " with admiration.\n"
                    << name << " felt proud and a little cocky.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "\"There are lot of creatures! They like to\n"
                    "play with travelers like you, " << name << "!\n"
                    "Are you sure you want to go there?\"\n"
                    << name << " proudly raised his/her head.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "Dorothy laughed and offered to lead " << name << "\n"
                    "to the garden. " << name << " received the offer.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "Dorothy and " << name << " went to the garden after some\n"
                    "hours. It was nice to go through beautiful meadow with the\n"
                    "pretty shepherdess. When they came to the karge arch of the\n"
                    "garden she said - \"Now you go alone.\"\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        Choice(level, name, inventory, InvSize);

        std::cout << "They said goodbye to each other and then " << name <<
                    "\ncontinued his/her journey through the Curly garden.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

    }
    else if(level == 3)
    {
        std::cout << "Having passed the fragrant garden, " << name <<
                    "\ncame to the curly trail. The sun was setting\n"
                    "over the horizon. It was quiet and peaceful.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << name << " was walking down the trail and his/her\n"
                "heart was filling peace in this place. " << name << "\n"
                "Flet so free and nice here.\n\n"
                "( Your power, defence and HP increases )\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "Then " << name << " noticed the tall tower not so far.\n"
                    "It was his/her last location to visit - The tower of mind.\n"
                    "The crazy itallian artist live there...\n"
                    "The tower looked weird. There was a fire in one of the windows.\n"
                    "A long dragon from stone were on the tower. Lots of banners and\n"
                    "Other strange things decoreted the tower.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << name << " was running by trail until he/she came to the\n"
                "roung grassless meadow. There was a man in the middle, sitting\n"
                "at the small round table and drinking tea. The table has a\n"
                "fish tail. Man in a purple cloak looked at " << name << " and\n"
                "smiled.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "\"Ah... hello?\" - Said " << name <<
                    ".\n\"Hellooo!\" - answered man, - \"Let me guess...\n"
                    "You are an another one traveler who so confident to\n"
                    "think that he/she can just come to my house and walk inside\n"
                    "it?\"\n"
                    << name << " blushed.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "\"Are you Richard Gravano&\" - asked " << name << "\n"
                    "\"I am. And I'm not very happy to see an another one\n"
                    "guest!\" - Richard drank some tea.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "He sighed. \"At first take a sit, call me your name\n"
                    "And make a company for me. I will decide will you go\n"
                    "after a talk.\"\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << name << "Took a sit. Richard poured some tea for\n"
                "him/her.\n"
                << name << "didn't notice how time passed. It was nice to\n"
                << name << " to talk with this strange artist. He was very\n"
                "interesting person. He told " << name << " lots off things\n"
                "about his tower and projects. " << name << " told him about\n"
                "his/her adventures.\n\n"
                "( Your power, defence and HP increases )\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "Moon was lighting. Richard looked in the sky\n"
                    "and yawned. His red eyes looked scary and beautiful\n"
                    "in the darkness. He smiled - \"Did you want to visit\n"
                    "my tower? Go.\"\n"
                    "\"But what about you?\" - asked " << name << ", -\n"
                    "\"Will you go?\"\n\n"
                    "- \"I need a break from the madness of my tower too!\"\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "And then " << name << "continued the journey.\n"
                    "The last location.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");
    }
    else if(level == 4)
    {
        std::cout << "After lots of hours of fights " << name << "\n"
                    "reached the top floor. There was a big door.\n"
                    "It should be the treasure behind this door!\n"
                    << name << " pushed it and saw a big round room.\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
        _getch();
        system("cls");

        std::cout << "There were no furniture or other objects in the\n"
                "room. But the walls...\n"
                "There were pictures on the walls.\n"
                "Pictures of " << name << "!\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
            _getch();
            system("cls");

        std::cout << "All " << name << "'s journey was drawn on the walls.\n"
                    "The Osman and his Echo swamps; then Dorothy\n"
                    "and sheep near by Curly garden. And the tea party with\n"
                    "Richard was drawn too! But where is the treasure?\n\n";
        std::cout << "||| Click \"Enter\" to continue. |||\n";
            _getch();
            system("cls");

        std::cout << "Watching the arts " << name << " realised\n\n"
                    "the most valuable thing in the world is your path.\n"
                    "Not reward as valuable as time you spend achieving\n"
                    "your goal. Emotions you got, people you met are\n"
                    "the greatful things.\n\n"
                    "Then " << name << " came back to his kingdom and\n"
                    "everione lived longly and happily.\n\n"
                    "\t\tTHE END\n\n"
                    "\t\tTHANKS FOR PLAYING!\n";
    }
    level++;
}

void Choice(short& level, std::string& name, Item inventory[], int& InvSize)
{
    Item tincture{"Osman's tincture", 10, 2};
    Item cookies{"Dorothy's cookies", 25, 1};
    short menuitem{};
    if(level == 1)
    {
        std::cout << name << " thanked Osman and took the talisman. Osman\n"
                    "smiled to " << name << " and took out a bottle with a drink\n"
                    "of strange purple colour. He drank a drink and offered some to\n"
                    << name << ". \"It is my cone tincture. Do you want to take some\n"
                    "for your journey?\"\n\n"
                    "1 - \"Yes!\"\n"
                    "0 - \"No...\"\n";
        std::cin >> menuitem;
        system("cls");
        if(menuitem && InvSize != 10)
        {
            inventory[InvSize++] = tincture;
            std::cout << "\"Why not? It would be rude to refuse!\" - thought\n"
                         << name << "and receive a bottle with the tincture.\n\n";
            std::cout << "||| Click \"Enter\" to continue. |||\n";
            _getch();
            system("cls");
        }
        else
        {   std::cout << "\"Ah... Thanks, but I don't really like alcohol, haha...\"\n"
                        "- " << name << " refused politely. He/she was afraid to take\n"
                        "weird tinctures from strangers\n\n";
            std::cout << "||| Click \"Enter\" to continue. |||\n";
            _getch();
            system("cls");
        }
    }
    else if(level == 2)
    {
        std::cout << name << " thanked Dorothy for her company.\n"
                "She looked happy. \"It will be a long journey. \n"
                "Would you like to take some cookies with you?\n"
                "That is not a lot but anyway...\"\n\n"
                "1 - \"Yes!\"\n"
                "0 - \"No...\"\n";
        std::cin >> menuitem;
        system("cls");
        if(menuitem && InvSize != 10)
        {
            inventory[InvSize++] = cookies;
            std::cout << name << " was happy to get some baking from an\n"
                    "adorable shepherdess. He/She received her gift with\n"
                    "pleasure.\n\n";
            std::cout << "||| Click \"Enter\" to continue. |||\n";
            _getch();
            system("cls");
        }
        else
        {
            std::cout << "Dorothy was so cute and adorable and she has\n"
                        "leaded " << name << " to the garden! " << name <<
                        "\nwas embarressed to receive something from her.\n"
                        "\"No need!\" - he/she answered\n\n";
            std::cout << "||| Click \"Enter\" to continue. |||\n";
            _getch();
            system("cls");
        }
    }
}


////////////////////////////////////////////////////////////
////////////////////ОБЛИКИ МОНСТРОВ/////////////////////////
////////////////////////////////////////////////////////////

void SetMonstersImage(Monster SwampMonsters[],
                        Monster GardenMonster[],
                        Monster CastleMonster[])
{
    SwampMonsters[0].SetPrint(
R"(
                     .:=+*##.                              
                    .*=-==-=-                              
                 -=====-*===*+++:                      
               .:=#====*==-+*+#-.       .+:            
            +===00000***00000=**++:.    -=.             
            .:=*00000==#00000=+.     .++=-=+:          
            .+=*00000+**00000+=.    .+=+===:.          
           ....:-:=*+*+**=--+**=--====..               
              .+*=**+00=#=**+:*:                       
              =-+=+*0000*+++**:-.                                           
          .=====.*+*+00++++*=+***.                     
          -=+=+-++:++++*++++*+*#-=                     
          ..+-:+.=*+-+++++++**+#=.::.                                         
            :-.:+=.-*=++***=+++++. ...                 
               .+:-*-*+=*..*+++*+*+..                              
               .-+++. :+:..=*:*-=*+..                  
                      .:  :#. .#-  .*+                 
                           :+:  ..     .           )"
    );

    SwampMonsters[1].SetPrint
    (R"(                                                      
                     @%*#@                            
                      #+#@ @@ @@   @*+*%                          
                 @@   #*#%  %%@    *+#                                
                   %#%%**% %@   @@@**%  %                                                                                 
               %        %***%%   #*+#%%                               
             @%@%        %+**%   **#*%                                
               @%#@      @***#% #***#%                                
                 %%%#%    ##*###+***##*#**%@                          
                     %#+**%#***+++**##%%%%%#*++**%                                
             %#%%@@@%@ @%@%%**+++++++*% @@        %**%  @@@           
           %%%@      @@    *@@*#@@%##%%#@  @@@       @%#@             
          @                #++*+++++%%    @@           %% @@          
                           #*@@@%*+*%%                                
                         %***@@%@@#+*##                               
                     @**%@ *++*+++*#%%**%                                                    
                   @#%     #****++*#%%  ##@                           
                @##**%     #*+**++*%%%  ##%                                                                          
             @@% %%@  %%   ********#%% ####%@                         
                 @@@    #********%% % #%@#%                                         
                      @*++++*+++++*#####%@@                          
                  @%**++++###*##+*+#**#%%#%@                          )");

    SwampMonsters[2].SetPrint(
        R"(                      
          . .=.:....   . .:--:*+*.. +  ..+.-.=.  .:  ::               
          .  :=.::--=:-:.*.*++++**-.:. .*.+-:. --:. -.=:              
          ..:.--::.-.  .=.:..........:+. ..=:-:-..  - -              
          . . :.::-:=-.- ..............  .::. -=.-. ::.              
          . .:.:-:----=:.  .+00....00.. .:.  .::+. -:=:.              
          .     ==-=.:-=:=-::00....00...-:    :-=. ..                 
          .   ....:+.:-:-*...00....00...-:--++*+--=.                  
          .    .:-.. . .   0..........0..-:....:.::--                                                                                 
               .-:   :--+....00000000...:.   .                         
                     .   :*..........:..  .:::.                      
                         .****=@+=%=+ +  .....::.                                          
                        .::=:-=+=**-=-. -.+-.                         
                        -:..-+-++:%= -. :-                            
                         .:+:=====+:. .=.                             
                            ---===+@=#%.                              
                             :=-==-+@%-.                              
        )"
    );

    SwampMonsters[3].SetPrint(
        R"(                      
                           -@@@+                                                           
                             %@@@@=                                                        
                             -@@@@@@@@@@@@@@@@@@@@%#.                                      
                         *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                  
                      @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@= :-@@@@                               
                   =@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.  :%@@@@@                             
             .   =@@@@@@=       =@@@@@@@@@@@@@@@@           *@@-                           
                %@@@@           .@@@*+   =@@@@*+-=+=-::=-.                                 
              @@@@@..*@@    ::::=+::---@@#=:                                              
       .-  : @@@@@@@@%++*=:        .=                                                     
    -   = @@@@@@@@. .                                                                   
   =  .-*@@@@@*:.+*::--:.                             .                                
  :  -:=@@@@*:. ..:  .- *         : -  -.                .:                            
.:..      .  ..   ...::.. . . ::      ....:-::::. :-.             :.:. .. .:                        
...  :. ...  :. ..     : ..     ...  ...   .:.  ..      ::::-: ..      :..              
        )"
    );

    SwampMonsters[4].SetPrint(
        R"(                      
                          -*%%#=                                                          
                        :#@@@@@@@-                                                        
                          =%@@%+.                                                         
                    .=#@@@@@@@@@@@@%:                                                       
                +@@%= :@@@@@@@@@@@@@@#+++#@@@@@-                                          
                  -@@@- =@@@@@@@@@@-   -===:                                                
                    :%@@@@@@@@@@@@@.                                                        
                        #@@@@@@@@@%.                                                        
                        @@@#:.:*@@@.                                                        
                       .@@@+   :@@@=                                                        
                       -@@@=   .%@@*                                                        
                       +@@@-    *@@@                                                        
                       #@@%:    =@@@-                                                       
                       @@@#.    :%@@*                                                       
                       @@@+     .*@@%                                                             
        )"
    );



    GardenMonster[0].SetPrint(
        R"(
                                                                                       
                                   ++##-++==- .-+                                      
                               =#=#--------------+-   .-                               
                            =-----=-------==--------=----=                             
                            +=-=*=--------**+----***------#+-                          
                   .:  ==-*++-----------------+##*+---------=*                         
                 =+--------+*#-----------------------+=-----===.**:                    
             +---*+--=++-----------=++*+--------------------#-----+:                   
             *---+=---**--------+#==-----**----------------=*#*+---===:                
           -----------==----------------------*##=--*+*--+=-----------+=               
            +---------------+#*----+*+=-----------+=+------#+--------==  .             
            #+-----------------+*--------=-=---=-------------------------*-            
            =++-----------------------------------------------=--=-----*=+             
                ...**+*+-+=-+-----=----*-+--*-#*+=+ :*+:  .:       . ..       
        )"
    );

    GardenMonster[1].SetPrint(
        R"(
                    -*#+:                                         
                   %      .%*                         +%-     #+  
                   ++        :@:                   ++        -%   
                    *+         :%                #.         %:    
           :=+**+-:. -%          #=            -=         #+      
      =*   *   %    -=-%@#*-      *+          +-        +#        
    *-    *:  +-   *    :@. :-:=.  #=        -+       =#            
  #       %.  #   %     *   =%:      %=-:   *    :#-              
 -%#*++++=**==****##@@*+%:     =%+:  :%--+*-. =*:  ..:            
                    @:-+#@+-      -*:=:     =*#+     .*           
                   :@ %.  #+-=+- #     #.  +    #-    -+          
                   +#  @-+  :+= .*  **  @  * **  #     +-         
                   #+  #+*-     .%  **  @  = ** =*      #         
                   #+  -% @      =#     :   *  #       --        
                   *#   @:#*       -#+:  *@++:         .*        
                   -@   +#+%             *@+             %        
                   .%    @ #*             %@                 -**. 
                 :%:    -+ :@.            .@                      
               ::      :%   .-             %=                     
                      ..    #.             **                     
        )"
    );

    GardenMonster[2].SetPrint(
        R"(
                            :..::.                      
                           .. .   ..                    
                             ..   :.:..:.                    
                      :      .=:             :          
                     :         :  .         .....       
                    .-  .      :: ..          .. ..     
                  :.  :.       .--..    . =*-.     .    
                :.      ...       :    .:-%@*      ..   
               :             .-==...:           .  .-   
       .-:==-::                  :.            ... .    
     -: .  :..                      .  ..      .:-=.    
   .-.   .   .                       ..  ...  :-:....   
 :.    :    ..                       ..  ..  .  . .. .  
 :     .    ..          .:    ..       .:. ::   .. .    
 .     ..    . .          ..     ..       :-     .            
 :.  .      .: .             ::.       .                
   :.       .:.:     :..      .   ...:                  
  .... ..::..:::.             :   .-:::.   ..           
             ..:.. .         -.......:.:-.              
                 .::::::-:-:.   ..::::                  
                              ..-..:..=.                

        )"
    );

    GardenMonster[3].SetPrint(
        R"(
                        . :-:- .                 
                        =**###*+.                
                       -##*::+##+                
                       =*#*::=##+.    ...        
            .-***#+-    +######*:  :**###**-     
            **#***##+     -===.   .+#*+:=*#*.    
           =##*...###:      :     :*#*-.:*#*-    
          .-+##**###+:.     :      =*#####*=     
             :***#+. :.     :    .:  :===-       
                   .   -.   :  .:   ..           
                   :=-:  -. : :: .--=.           
                   .====-.:-=-.:====-            
                     -====:.-.-====:             
                       :::-:----:.               
                          -=.                   
                          .-:                    
        )"
    );

    GardenMonster[4].SetPrint(
        R"(
            ::==+==:::             . ..:..                
           -       :-=--         :+*#****#*=-.             
          *      * .:+       -*************##-           
         -        *- ++.  .=#****************#=          
         .  **   .=:  =*#*#**********************         
           .-+=:   +***************************#+        
              =-  :+****************************%.       
               :==***************#**************#:       
                -#***************#**************#:       
                  ##*#****#====####*************#+--     
                 .=**#***=      +#%##****************+   
                ==*==-+*-      :=-:+*+****************+  
                  .:::.              .#***************+  
                                      =*#+==+*#****##+   
                                       -:      :=-:.       
        )"
    );

    CastleMonster[0].SetPrint(
        R"(
*****************************************************
*             .::::..::.:::::...                    * 
*           .::...................:...              * 
*         .:...........................::.          * 
*        ::..:............................:.        * 
*      .:...-:.............. ..............::       * 
*    .:....:-:...........................:::::.     * 
*   .:.....--:........:.. .............:::=::.:---. * 
*  .:.....:=::........:..  ..:..........:+:::..:::. * 
*  .:.....--::::.....:::...::.....:::....-:.....::  * 
*  ::.....--:-=-:...:-:..:--..::-=-::...........:.  * 
*  ::....::--.:-:::-.  . .:-:...:-:-......-=....:   * 
*  ::......:=.:-:--. .:-:.  .:--..:::.::...:.:-:    * 
*  .:........::-:.:.  ..:..  :.:..:.::..::.....     * 
*   ::..........:::-::..     .--::.:::-:..-:=:      * 
*   .:=:...........::--.      ......:-.:::...       * 
*     ..::...........::.              ...           * 
*       ..::-::...::::-.                            * 
*           ............                            * 
*                 ....                              * 
*****************************************************
        )"
    );

        CastleMonster[1].SetPrint(
        R"(
           ..:::.                                      
          .=##++==+=:.      .    -.      .             
            .=+::-=:=+=.   ..    .                     
              .+=  -+--++: .... :. .  :       .        
          ..    -*=. =+--+-  :.   .  :     ..          
           ... .. ++. .=+-**:... .  .  .  :.           
             ..  . .**...==++.. .. . :. ..             
        ..  ..  . :: :++-.:+*-:.:...: .   ..  ..       
          ... :: ...: :.:=**#*:::. .:. :.  ...         
             .  .. ...:::....-#-.:::..:                
      ... :====-:  : .::--=-::::-:    .:=====:....     
         .....:-======: ::=+=-:. :======-:...:.        
       .:. ..:---..::.:-::....:--:.:: .--::.. .:.      
      :#=.::..:--:.::... ..**.. ...::.:--:..::.+*:     
     :*+..::::-==:.::...   **   ...::.:==-::::..*+.    
    .*%+===+++++==-:....   **   ....:===+++++===*%+.   
   .+%#******++++**#*+=-.  **  :==+*#*+++++******#%=.  
  .+%+---=========--======-**-=====---=========---*%=  
  =%#++++++++******######%%@@%%######******++++++++#%- 
 :##******+++++++======--=++++=-=======++++++*******#*.
        )"
        
    );


        CastleMonster[2].SetPrint(
        R"(      
     .=.#-#. .-          -#.                  
    .=##. .#: =%:.      .**-        .:+-      
  .=#...   :+ .**#.     :+:+     .:##%.       
  ==     ..+-   :%-**=:.  .:+#%:..#:          
.*#########%:  .=#..          .:##.           
 -*:::::::-%==+%:..-=******=:.   :*:-+***%*-. 
  .=%+%=.*..+*.       .:.       .#-.*-        
  -=   -+*.*-     ..=*+:-*+.      .++%*++--.. 
  -=   .%%%-  :=**+:.     .-*+:.    .*#*+.    
  .*...==##. :* ***          ***%=....==.     
   -#=-:.*-*:#  ***          ***..:#. .%.     
   .---*-:.=%.  ***    ==    ***. :#. .%.     
       :#. .+=.     **    **      -*..+:      
       .-+  .-=       ****        =+.%:       
         +-  .-%**++==-----==++*##=#:.*.          
          .#..+:==  +:.:-:..*+. .#..#:.=#.    
           :*==.*.  .=*+=+#*.   .#++.   .*=.  
           .*-.#-.     .-*.  .*- *: .-###.      
             .*   .-*=.    . .%. --:+.:%*.    
             .+:=#=.      .+..#. :++=-..+.    
             -+...        :+ :#  .#.. .%:.    
             ==          .#: -*  .#.-++.      
             +-         .=+  =-.::#:.         
             *-         .*   ++*#:*=            
             #:       .*##+  .#.=+.#.         
             #:...:+##=..*:  .#.:*.#:
        )"  
    );
    
            CastleMonster[3].SetPrint(
        R"(      
##%%%**###%%%%%%%%%%#%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%#*#####%#***##*++****##%%%%%%%%%%%%%%%%%
%%%%%%%%#########***=++=====++*#%%%%%%%%%%%%%%
%%%%%%%%%#**##*++****=+========++#%%%%%%#%%%%%
%%#%##%######++++****=+-========++*%%###%%%%%%
############++==+****=+=-==+*+===++*#########%
%##%#######*++===+++*+=++====*+==+++#########%
%%%%#####**=+=====+*+--=-==**+++++++###%###%%%
%%%%%%###****+++=+==----=+++++++++**##%%%%%%%%
@@@@%%%%%%%#****++---:---=*#*+****##%%%%%%%%%@
@@@@%%%%%%%#######--:-=++-=##*###%%%%%%%%%%%@@
@@@@@%%%%%%%%%%#%#-::=*#%*-****#%%%%%%%%%%%@@@
%@%@%%%%%%%%%%%%%+-::-+*++======*%%%%%%%%%%%%%
%%%%%%%%%#####=::::---===++*+=**#*####%%%%%%%%
%%%%%%%%%%%#---::::----==+*####**#%%%%%%%%%%%%
%%%%%%%%%%%%%%%%#%%%%%###%%%%+*###%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%#*+*%%%%#**##%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%===%%%*+###%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%#==##**##%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%#####+#*#################%%%%
%%%%%%%%#####%%%%%%%%#*#**#%%%%%%##########%%%
%%%%%%%%#####*#######++#**###########%%%%%#%%%
%%%%####%#######*#####+##*###########%%%%#*#%%
        )"  
    );

            CastleMonster[4].SetPrint(
        R"(
@++++++++++++++++++++++++++++++++@
%-==-======*=-------*===-=======-%
%-========*====++++==++++*+++===-%
%-=====-==+---===++=----------=*=%
%====---=-=+---------+===------=-%
%:::-=++*+++*======*+==---=-====-%
%:::::----------------==*#*+++++=%
%-======----==-==-==------===----%
%:------=+*=---::-+*=---=--==+*=-%
%-===-*##***#*+=-=-+==----=-====-%
%==--------------=*#=-===--==----%
%=+=====+******-=####+-::-=*+===-%
%=+***+*****++#############*=--::%
%*%%%%%%%%%%%%%%#**%*******##%#%*%
%=+*****+***#***#####**##*****++=%
%=+++++++***++++++++********++++=%
%+******#***********************+%
%*#****##%%####*********###%%##*+%
%*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*%
%*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*%
@+++++++++++++++++++++++++=======%
        )"
        
    );
}