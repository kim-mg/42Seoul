from django.contrib import admin
from django.urls import path
from ex00 import views as ex00views
from ex01 import views as ex01views
from ex02 import views as ex02views
from ex03 import views as ex03views

urlpatterns = [
    path('admin/', admin.site.urls),
    path('ex00/', ex00views.ex00, name='index'),
    path('ex01/django/', ex01views.ex01_django, name='django'),
    path('ex01/display/', ex01views.ex01_display, name='display'),
    path('ex01/templates/', ex01views.ex01_templates, name='templates'),
    path('ex02/', ex02views.ex02, name='form'),
    path('ex03/', ex03views.ex03, name='bic'),
]
