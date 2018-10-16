from django.db import models

# Create your models here.

class UserLog(models.Model):
    userlogid = models.AutoField(primary_key=True)
    fullname = models.CharField(max_length=150)
    email = models.CharField(max_length=100)


class EquationLog(models.Model):
    mass = models.FloatField(null=False)
    acceleration = models.FloatField(null=False)
    force = models.FloatField(null=False)
    userlogid = models.ForeignKey(to=UserLog, on_delete=models.PROTECT)

