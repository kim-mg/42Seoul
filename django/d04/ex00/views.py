from django.shortcuts import render

# Create your views here.
def ex00(request):
    title = 'Ex00: Markdown Cheatsheet.'
    return render(request, 'ex00/index.html', {'ex00_title': title})
