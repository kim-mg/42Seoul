from django.shortcuts import render

# Create your views here.
def ex01_django(request):
    return render(request, 'ex01/django.html')

def ex01_display(request):
    return render(request, 'ex01/display.html')

def ex01_templates(request):
    return render(request, 'ex01/templates.html')