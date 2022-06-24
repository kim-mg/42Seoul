from django.shortcuts import render

# Create your views here.
def ex03(request):
    weight = 1 / 50
    shadows = []
    i = 1
    for l in range(0, 50):
        shadows.append(i - l * weight)

    return render(request, 'ex03/bic.html', {'shadows': shadows})