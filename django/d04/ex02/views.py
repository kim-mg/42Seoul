from django.shortcuts import render
from .forms import PostForm
import logging

# Create your views here.
logger = logging.getLogger(__name__)
def ex02(request):
    if request.method == 'POST':
        form = PostForm(request.POST)
        if form.is_valid():
            logger.debug(form.cleaned_data['text'])
    else:
        form = PostForm()
    try:
        file = open("ex02/logs.log", "r")
        context = file.readlines()
        file.close()
    except:
        print("log not opened")
        
    return render(request, 'ex02/form.html', {'form': form, 'context': context})