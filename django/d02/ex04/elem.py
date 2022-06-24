#!/usr/bin/python3

class Text(str):
    """
    A Text class to represent a text you could use with your HTML elements.

    Because directly using str class was too mainstream.
    """
    def __init__(self, input = ''):
        if input == '<':
            input = '&lt;'
        elif input == '>':
            input = '&gt;'
        elif input == '"':
            input = '&quot;'
        if not isinstance(input, str):
            input = str(input)
        self.input = input

    def __str__(self):
        """
        Do you really need a comment to understand this method?..
        """
        return self.input.replace('\n', '\n<br />\n')


class Elem:
    """
    Elem will permit us to represent our HTML elements.
    """
    def __init__(self, tag='div', attr={}, content=None, tag_type='double'):
        """
        __init__() method.

        Obviously.
        """

        if content == None:
            self.content = []
        else:
            self.content = []
            self.add_content(content)
        self.tag = tag
        self.attr = attr
        self.tag_type = tag_type
        self.indent_level = 0

    def __str__(self):
        """
        The __str__() method will permit us to make a plain HTML representation
        of our elements.
        Make sure it renders everything (tag, attributes, embedded
        elements...).
        """
        if self.tag_type == 'double':
            if self.content != None:
                result = self.tag_open() + self.__make_content() + self.tag_close()
            else:
                result = self.tag_open() + self.tag_close()
        elif self.tag_type == 'simple':
            result = self.tag_open() + self.__make_content()
        return result

    def __make_attr(self):
        """
        Here is a function to render our elements attributes.
        """
        result = ''
        for pair in sorted(self.attr.items()):
            result += ' ' + str(pair[0]) + '="' + str(pair[1]) + '"'
        return result

    def tag_open(self):
        if self.tag_type != 'double':
            rtn = '<' + self.tag + self.__make_attr() + ' />'
        else:
            rtn = '<' + self.tag + self.__make_attr() + '>'
        return rtn
    
    def tag_close(self):
        if self.__make_content():
            rtn = '  ' * self.indent_level + '</' + self.tag + '>'
        else:
            rtn = '</' + self.tag + '>'
        return rtn

    def check_indent(self, elem):
        if isinstance(elem, Elem):
            elem.indent_level += 1
        if elem.content and isinstance(elem.content[0], Elem):
            elem.check_indent(elem.content[0])

    def __make_content(self):
        """
        Here is a method to render the content, including embedded elements.
        """
        if len(self.content) == 0:
            return ''
        result = ''
        for elem in self.content:
            if isinstance(elem, Elem):
                self.check_indent(elem)
            result += '\n  ' + '  ' * self.indent_level + str(elem)
        result += '\n'
        return result

    class ValidationError(Exception):
        def __init__(self):
            super().__init__("incorrect behaviour.")

    def add_content(self, content):
        if not Elem.check_type(content):
            raise Elem.ValidationError
        if type(content) == list:
            self.content += [elem for elem in content if elem != Text('')]
        elif content != Text(''):
            self.content.append(content)

    @staticmethod
    def check_type(content):
        """
        Is this object a HTML-compatible Text instance or a Elem, or even a
        list of both?
        """
        return (isinstance(content, Elem) or type(content) == Text or
                (type(content) == list and all([type(elem) == Text or
                                                isinstance(elem, Elem)
                                                for elem in content])))

if __name__ == '__main__':
    html = Elem(tag='html', content=[Elem(tag='head', content=Elem(tag='title', content=Text("Hello ground!"), tag_type='double'), tag_type='double'), Elem(tag='body', content=[Elem(tag='h1', content=Text("Oh no, not again!"), tag_type='double'), Elem(tag='img', attr={"src": "http://i.imgur.com/pfp3T.jpg"}, tag_type='simple')], tag_type='double')], tag_type='double')
    print(html)
