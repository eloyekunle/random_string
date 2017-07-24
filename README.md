I sure thought writing a native PHP extension in C++ would make string generation faster for the thousands I'll have to generate periodically in my web service.

Boy, was I wrong.

Well, here's the source code, tested and working on Ubuntu 17.04.
You might have to edit the Makefile to the appropriate PHP extensions location on your computer.

It's based on [PHP-CPP](http://www.php-cpp.com/documentation/introduction)
You'll have to [install](http://www.php-cpp.com/documentation/install) PHP-CPP on your server, then download appropriate php-dev tools for your server.
This should work just fine on Ubuntu;
```
sudo apt-get install php7.0-dev
```

Compiling:
```
make
```

Then to install;
```
sudo make install
```

Oh, well. What a beautiful day.

[Elijah Oyekunle](https://elijahoyekunle.com)