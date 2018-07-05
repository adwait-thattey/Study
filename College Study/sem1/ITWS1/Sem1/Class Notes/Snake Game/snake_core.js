var game_over = false;
var snake = new Array(4);
var snakeLen = 4;
var dir = "right";
var food = "";
var image_size=32;
var total_height = canvas.height/image_size;
var total_width = canvas.width/image_size;
context1.font = "30px Arial";

snakeHeadImage = new Image();
snakeHeadImage.src = "resources/head.png";
snakeBodyImage = new Image();
snakeBodyImage.src = "resources/body.png";
snakeTailImage = new Image();
snakeTailImage.src = "resources/tail.png";

//food
foodImage = new Image();
foodImage.src = "resources/food.png";

//Initialization
create_snake();
create_food();
function create_snake()
{
	snake[0] = {xx: 4, yy: 1};
	snake[1] = {xx: 3, yy: 1};
	snake[2] = {xx: 2, yy: 1};
	snake[3] = {xx: 1, yy: 1};
	dir = "right";
}
function create_food()
{
	var x = 0;
	var y = 0;
	var recreate = false;
	do
	{
		recreate = false;
		x =  1+Math.floor((Math.random() * (total_width-1)));
		y =  1+Math.floor((Math.random() * (total_height-1)));
		
		for(i = 0; i < snakeLen; i++)
		{
			if( (snake[i].xx == x) && (snake[i].yy == y) )
			{
				recreate = true;
				break;
			}
		}
	}while(recreate == true);
	food = {xx: x, yy: y};
}



setInterval(function() {animate();}, 250);


function animate()
{
	move_snake();
	if(game_over == false)
	{
		// clear
		context.clearRect(0, 0, canvas.width, canvas.height);
		context1.clearRect(0, 0, canvas1.width, canvas1.height);
		context1.fillText("Score: " + (snakeLen - 4), 30, 30);
		display();
	}
	else
	{
		context1.fillText("Hahaha.. Game Over", 170, 30);
	}
} 

function move_snake()
{
	var temp_x = 0;
	var temp_y = 0;
	var temp_xx = 0;
	var temp_yy = 0;
	var swap = true;

	//move snake forward
	for(var ii = 0; ii < snakeLen; ii++)
	{		
		if(ii == 0)
		{
			temp_x = snake[ii].xx;
			temp_y = snake[ii].yy;

			//if head moving right
			if(dir == "right")
			{
				snake[0] = {xx: (snake[0].xx + 1), yy: snake[0].yy};
			}
			else if(dir == "left")
			{
				snake[0] = {xx: (snake[0].xx - 1), yy: snake[0].yy};
			}
			else if(dir == "up")
			{
				snake[0] = {xx: snake[0].xx, yy: (snake[0].yy - 1)};
			}
			else if(dir = "down")
			{
				snake[0] = {xx: snake[0].xx, yy: (snake[0].yy + 1)};
			}
			
			if(checkSnakeCollide())
			{
				snake.push({xx: snake[(snake.length-1)].xx, yy: snake[(snake.length-1)].yy});
				snakeLen++;
			}
		}
		else
		{
			if(swap == true)
			{
				temp_xx = snake[ii].xx;
				temp_yy = snake[ii].yy;
				snake[ii] = {xx: temp_x, yy: temp_y};

				swap = false;
			}
			else
			{
				temp_x = snake[ii].xx;
				temp_y = snake[ii].yy;
				snake[ii] = {xx: temp_xx, yy: temp_yy};
				swap = true;
			}
		}
	}

}

function checkSnakeCollide()
{
	if( snake[0].xx == food.xx && snake[0].yy == food.yy )
	{
		create_food();
		return true;
	}
	else
	{
		//if head moving right
		if(dir == "right")
		{
			if(snake[0].xx > total_width - 1)
			{
				game_over = true;
			}
		}
		else if(dir == "left")
		{
			if(snake[0].xx < 1)
			{
				game_over = true;
			}
		}
		else if(dir == "up")
		{
			if(snake[0].yy < 1)
			{
				game_over = true;
			}
		}
		else if(dir = "down")
		{
			if(snake[0].yy > total_height-1)
			{
				game_over = true;
			}
		}
		
		for(i = 2; i < snakeLen; i++)
		{
			if( (snake[0].xx == snake[i].xx) && (snake[0].yy == snake[i].yy) )
			{
				game_over = true;
				break;
			}
		}
		
		return false;
	}
}



function display()
{
	
	for(var i = 0; i < snakeLen; i++)
	{
		if(i == 0)
		{
			switch (dir)
			{
				case "right":
					drawRotatedImage(snakeHeadImage,(snake[i].xx * image_size), (snake[i].yy * image_size), 180);
					break;
				case "left":
					drawRotatedImage(snakeHeadImage, (snake[i].xx * image_size), (snake[i].yy * image_size),0 ); 
					break;
				case "up":
					drawRotatedImage(snakeHeadImage,(snake[i].xx * image_size), (snake[i].yy * image_size), 90);
					break;
				case "down":
					drawRotatedImage(snakeHeadImage,(snake[i].xx * image_size), (snake[i].yy * image_size), 270);
					break;
			}
		}
		else if(i == (snakeLen - 1) )
		{
			//following left
			if(snake[i].xx > snake[i-1].xx)
			{
				drawRotatedImage(snakeTailImage, (snake[i].xx * image_size), (snake[i].yy * image_size),0 ); 
			}
			//following right
			else if(snake[i].xx < snake[i-1].xx)
			{
				drawRotatedImage(snakeTailImage,(snake[i].xx * image_size), (snake[i].yy * image_size), 180);
			}
			//following up
			else if(snake[i].yy > snake[i-1].yy)
			{
				drawRotatedImage(snakeTailImage,(snake[i].xx * image_size), (snake[i].yy * image_size), 90);
			}
			//following down
			else if(snake[i].yy < snake[i-1].yy)
			{
				drawRotatedImage(snakeTailImage,(snake[i].xx * image_size), (snake[i].yy * image_size), 270);
			}
		}
		else
		{
			drawRotatedImage(snakeBodyImage, (snake[i].xx * image_size), (snake[i].yy * image_size),180 ); 
		}

	}
	
	context.drawImage(foodImage, (food.xx * image_size), (food.yy * image_size) ); 

}

function drawRotatedImage(image, x, y, angle) 
{ 
	var TO_RADIANS = Math.PI/180; 

	// save the current co-ordinate system 
	// before we screw with it
	context.save(); 
 
	// move to the middle of where we want to draw our image
	context.translate(x, y);
 
	// rotate around that point, converting our 
	// angle from degrees to radians 
	context.rotate(angle * TO_RADIANS);
 
	// draw it up and to the left by half the width
	// and height of the image 
	context.drawImage(image, -(image.width/2), -(image.height/2));
 
	// and restore the co-ords to how they were when we began
	context.restore(); 
}
