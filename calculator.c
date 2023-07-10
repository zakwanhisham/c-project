#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    float value_one;
    float value_two;
    char operator;
    float answer;

    printf("Enter calculation:\n");
    scanf("%f %c %f", &value_one, &operator, & value_two);

    switch (operator) {
    case '/':
        answer = value_one / value_two;
        break;
    case '*':
        answer = value_one * value_two;
        break;
    case '+':
        answer = value_one + value_two;
        break;
    case '-':
        answer = value_one - value_two;
        break;
    case '^':
        answer = pow(value_one, value_two);
        break;
    case ' ':
        answer = sqrt(value_two);
        break;
    default:
        goto fail;
    }
    printf("%.9g%c%.9g = %.6g\n\n", value_one, operator, value_two, answer);
    goto exit;
fail:
    printf("Fail.\n");
exit:
    return 0;
}
