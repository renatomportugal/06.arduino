<!-- TOC -->

- [1. An exhibit of Markdown](#1-an-exhibit-of-markdown)
    - [1.1. Basic formatting](#1-1-basic-formatting)
    - [1.2. Lists](#1-2-lists)
        - [1.2.1. Ordered list](#1-2-1-ordered-list)
        - [1.2.2. Unordered list](#1-2-2-unordered-list)
    - [1.2. Paragraph modifiers](#1-2-paragraph-modifiers)
        - [1.2.1. Code block](#1-2-1-code-block)
        - [1.2.2. Quote](#1-2-2-quote)
    - [1.2. Headings](#1-2-headings)
        - [1.2.1. Headings *can* also contain **formatting**](#1-2-1-headings-can-also-contain-formatting)
        - [1.2.2. They can even contain `inline code`](#1-2-2-they-can-even-contain-inline-code)
    - [1.2. URLs](#1-2-urls)
    - [1.3. Horizontal rule](#1-3-horizontal-rule)
    - [1.4. Images](#1-4-images)
    - [1.5. Finally](#1-5-finally)

<!-- /TOC -->

# 1. An exhibit of Markdown

This note demonstrates some of what [Markdown][1] is capable of doing.

*Note: Feel free to play with this page. Unlike regular notes, this doesn't automatically save itself.*

<a id="markdown-11-basic-formatting" name="11-basic-formatting"></a>

## 1.1. Basic formatting

Paragraphs can be written like so. A paragraph is the basic block of Markdown. A paragraph is what text will turn into when there is no reason it should become anything else.

Paragraphs must be separated by a blank line. Basic formatting of *italics* and **bold** is supported. This *can be **nested** like* so.

<a id="markdown-12-lists" name="12-lists"></a>

## 1.2. Lists

<a id="markdown-121-ordered-list" name="121-ordered-list"></a>

### 1.2.1. Ordered list

1. Item 1
2. A second item
3. Number 3
4. Ⅳ

*Note: the fourth item uses the Unicode character for [Roman numeral four][2].*

<a id="markdown-122-unordered-list" name="122-unordered-list"></a>

### 1.2.2. Unordered list

* An item
* Another item
* Yet another item
* And there's more...

<a id="markdown-12-paragraph-modifiers" name="12-paragraph-modifiers"></a>

## 1.2. Paragraph modifiers

<a id="markdown-121-code-block" name="121-code-block"></a>

### 1.2.1. Code block

    Code blocks are very useful for developers and other people who look at code or other things that are written in plain text. As you can see, it uses a fixed-width font.

You can also make `inline code` to add code into other things.

<a id="markdown-122-quote" name="122-quote"></a>

### 1.2.2. Quote

> Here is a quote. What this is should be self explanatory. Quotes are automatically indented when they are used.

<a id="markdown-12-headings" name="12-headings"></a>

## 1.2. Headings

There are six levels of headings. They correspond with the six levels of HTML headings. You've probably noticed them already in the page. Each level down uses one more hash character.

<a id="markdown-121-headings-can-also-contain-formatting" name="121-headings-can-also-contain-formatting"></a>

### 1.2.1. Headings *can* also contain **formatting**

<a id="markdown-122-they-can-even-contain-inline-code" name="122-they-can-even-contain-inline-code"></a>

### 1.2.2. They can even contain `inline code`

Of course, demonstrating what headings look like messes up the structure of the page.

I don't recommend using more than three or four levels of headings here, because, when you're smallest heading isn't too small, and you're largest heading isn't too big, and you want each size up to look noticeably larger and more important, there there are only so many sizes that you can use.

<a id="markdown-12-urls" name="12-urls"></a>

## 1.2. URLs

URLs can be made in a handful of ways:

* A named link to [MarkItDown][3]. The easiest way to do these is to select what you want to make a link and hit `Ctrl+L`.
* Another named link to [MarkItDown](http://www.markitdown.net/)
* Sometimes you just want a URL like http://www.markitdown.net/.

<a id="markdown-13-horizontal-rule" name="13-horizontal-rule"></a>

## 1.3. Horizontal rule

A horizontal rule is a line that goes across the middle of the page.

---

It's sometimes handy for breaking things up.

<a id="markdown-14-images" name="14-images"></a>

## 1.4. Images

Markdown can also contain images. I'll need to add something here sometime.

<a id="markdown-15-finally" name="15-finally"></a>

## 1.5. Finally

There's actually a lot more to Markdown than this. See the official [introduction][4] and [syntax][5] for more information. However, be aware that this is not using the official implementation, and this might work subtly differently in some of the little things.


  [1]: http://daringfireball.net/projects/markdown/
  [2]: http://www.fileformat.info/info/unicode/char/2163/index.htm
  [3]: http://www.markitdown.net/
  [4]: http://daringfireball.net/projects/markdown/basics
  [5]: http://daringfireball.net/projects/markdown/syntax