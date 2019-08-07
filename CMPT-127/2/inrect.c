// #include <stdio.h>

int InRectangle(float pt[2], float rect[4])
{
    float pointX = pt[0], pointY = pt[1];
    float rectX1 = rect[0], rectY1 = rect[1], rectX2 = rect[2], rectY2 = rect[3];
    
    if (rectX1 < rectX2 && rectY1 > rectY2)
    {
        if (pointX >= rectX1 && pointX <= rectX2 && pointY >= rectY2 && pointY <= rectY1)
        {
            return 1;
        }
    }
    else if (rectX1 < rectX2 && rectY1 < rectY2)
    {
        if (pointX >= rectX1 && pointX <= rectX2 && pointY >= rectY1 && pointY <= rectY2)
        {
            return 1;
        }
    }
    else if (rectX1 > rectX2 && rectY1 > rectY2)
    {
        if (pointX >= rectX2 && pointX <= rectX1 && pointY >= rectY2 && pointY <= rectY1)
        {
            return 1;
        }
    }
    else if (rectX1 > rectX2 && rectY1 < rectY2)
    {
        if (pointX >= rectX2 && pointX <= rectX1 && pointY >= rectY1 && pointY <= rectY2)
        {
            return 1;
        }
    }

    return 0;
}

// int main()
// {
//     float point[2] = {53.75,8.472068};
//     float rectangle[4] = {-3.79,-17.123922,-85.29,5.34};

//     int result = InRectangle(point, rectangle);
//     if (result == 0)
//     {
//         printf("0\n");
//     }
//     else
//     {
//         printf("1\n");
//     }
// }