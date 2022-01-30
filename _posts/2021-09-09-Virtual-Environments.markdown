---
layout: post
title:  "Virtual Environments"
date:   2021-09-09 16:04:53 +0100
categories: jekyll update
draft: false
---

This post is a brief step-by-step guide to setting up a virtual environment in python using the venv module, and why you might want to use one. It is mainly for when I inevitably forget.

**What is a virtual environment?**

From the python docs, a virtual environment is:

 *"A cooperatively isolated runtime environment that allows Python users and applications to install and upgrade Python distribution packages without interfering with the behaviour of other Python applications running on the same system."*

**Why use one?**

Suppose you have a project A which makes use of version 1.0 of some module. Now suppose you later create a project B which requires version 2.0 of the same module. If you update the modules, then the different requirements might cause A to not work properly. Using a virtual environment means that different projects can use different instances of packages, so that updating packages will not break any old projects that may have relied on older versions. Different applications can then use different virtual projects!

**How can you create one?**

- To create a venv named 'my_venv', run the following from the command line:

{% highlight Python %}
  python3 -m venv my_venv
{% endhighlight %}

- Creating a virtual environment will also create a copy of the python interpreter, the standard library, along with some necessary files. You can see some of these files by typing 

{% highlight Python %}
  pip3 list
{% endhighlight %}

**A side note on modules**
- Any python file is a module, with name equal to the file's name without the .py
- A package is a collection of modules
- the -m flag in the terminal tells the interpreter to treat the following name as a module and not a program

**How to start using it?**
- Once you have created a virtual environment, you need to activate it to use it. To activate my_env, you would write 
{% highlight Python %}
  source my_env -env/bin/activate
{% endhighlight %}


The version of python within this environment will be the same version as that which was used to create the environment.


**What if someone else wants to work on the project?**

In order to work on a project from a virtual environment, you obviously need to make sure you have the correct versions of all the packages from that environment. The standard solution is to create a 'requirements.txt' file as part of the project, which can be used to see which packages were used for the project, and their versions. In order to get the list of packages from a project, as well as their versions, use the command

{% highlight Python %}
  pip freeze
{% endhighlight %}

Then you can directly ouput this to a text file via

{% highlight Python %}
  pip freeze > requirements.txt
{% endhighlight %}


Now someone else can install the list of required packages using 

{% highlight Python %}
  pip install -r requirements.txt
{% endhighlight %}


**How can I leave the virtual environment?**

Run the command 
{% highlight Python %}
  deactivate
{% endhighlight %}



**Where do I put the virtual environment**

- Typically you would create a venv directory within your project directory. For example, for a project named 'my_project', you would say

{% highlight Python %}
  python3 -m venv my_project/my_venv
{% endhighlight %}


And you would activate it via:
{% highlight Python %}
  source my_project/my_venv/bin/activate
{% endhighlight %}



**Things not to do**

- Don't place files *inside* the venv folder

- You should not commit your virtual environment to source control. That is, you typically place it in a .gitignore file. The requirements.txt file is enough.

For an explanation in video format, see https://www.youtube.com/watch?v=Kg1Yvry_Ydk.