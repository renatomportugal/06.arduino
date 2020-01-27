- [1. Task Lists](#1-task-lists)
- [2. Footnotes](#2-footnotes)
- [3. Syntax Highlighting](#3-syntax-highlighting)
- [4. Fenced Code Blocks](#4-fenced-code-blocks)
- [5. Escaping Characters](#5-escaping-characters)
  - [5.1. backslash](#51-backslash)
- [6. pound sign](#6-pound-sign)
- [7. Links](#7-links)
  - [7.1. Tiles](#71-tiles)
  - [7.2. URLs and Email Addresses](#72-urls-and-email-addresses)
  - [7.3. Formatting Links](#73-formatting-links)
- [8. TABELA](#8-tabela)
  - [8.1. BOLD](#81-bold)
  - [8.2. ITALIC](#82-italic)
  - [8.3. BOLD AND ITALIC](#83-bold-and-italic)
  - [8.4. Blockquotes](#84-blockquotes)
    - [8.4.1. Blockquotes with Multiple Paragraphs](#841-blockquotes-with-multiple-paragraphs)
    - [8.4.2. Nested Blockquotes](#842-nested-blockquotes)
    - [8.4.3. Blockquotes with Other Elements](#843-blockquotes-with-other-elements)
- [9. Lists](#9-lists)
  - [9.1. Ordered Lists](#91-ordered-lists)
  - [9.2. Nested Lists](#92-nested-lists)
  - [9.3. Unordered Lists](#93-unordered-lists)
  - [9.4. Nesting List Items](#94-nesting-list-items)
  - [9.5. Code](#95-code)
      - [9.5.1. Heading level 4](#951-heading-level-4)
        - [9.5.1.1. Heading level 5](#9511-heading-level-5)
          - [9.5.1.1.1. Heading level 6](#95111-heading-level-6)

# 1. Task Lists
- [x] Write the press release
- [ ] Update the website
- [ ] Contact the media

# 2. Footnotes
Here's a simple footnote,[^1] and here's a longer one.[^bignote]

[^1]: This is the first footnote.
[^bignote]: Here's one with multiple paragraphs and code.
Indent paragraphs to include them in the footnote.

`{ my code }`

Add as many paragraphs as you like.


# 3. Syntax Highlighting
```json
{
"firstName": "John",
"lastName": "Smith",
"age": 25
}
```


# 4. Fenced Code Blocks
```
{
"firstName": "John",
"lastName": "Smith",
"age": 25
}
```

# 5. Escaping Characters
\* Without the backslash, this would be a bullet in an unordered list.

## 5.1. backslash
You can use a backslash to escape the following characters.

| Character | Name | xxxxxxx |
| :--- | :----: | ---: |
| \ | backslash | x |
| ` | tickmark | x |
| * | asterisk | x |
| _ | underscore | xx |
| {} | curly braces | xxx |
| [] | brackets | xx |
| () | parentheses | x |

# 6. pound sign
+ plus sign
- minus sign (hyphen)
. dot
! exclamation mark


---

# 7. Links
Use [Duck Duck Go](https://duckduckgo.com).

## 7.1. Tiles
Use [Duck Duck Go](https://duckduckgo.com "My search engine!").

## 7.2. URLs and Email Addresses
<https://eff.org>
<fake@example.com>


## 7.3. Formatting Links
I love supporting **[EFF](https://eff.org)**.
This is the *[EFF](https://eff.org)*.

---

# 8. TABELA

| Syntax | Description |
| ----------- | ----------- |
| Header | Title |
| Paragraph | Text |

---

## 8.1. BOLD
I love **bold text**.
I love __bold text__.
Love**is**bold

## 8.2. ITALIC
The *cat's meow*.

## 8.3. BOLD AND ITALIC
***Important*** text
___Important___ text
__*Important*__ text.
**_Important_** text.

## 8.4. Blockquotes
> Dorothy followed her through many rooms.

### 8.4.1. Blockquotes with Multiple Paragraphs
> This the first paragraph.
>
> And this is the second paragraph.

### 8.4.2. Nested Blockquotes
> This the first paragraph.
>
>> And this is the nested paragraph.

### 8.4.3. Blockquotes with Other Elements
> ##### The quarterly results look great!
>
> - Revenue was off the chart.
> - Profits were higher than ever.
>
> *Everything* is going **well**.

# 9. Lists

## 9.1. Ordered Lists
1. First item
2. Second item
3. Third item
4. Fourth item

1. First item
1. Second item
1. Third item
1. Fourth item

1. First item
8. Second item
3. Third item
5. Fourth item

## 9.2. Nested Lists
1. First item
2. Second item
3. Third item
    1. Indented item
    2. Indented item
4. Fourth item

## 9.3. Unordered Lists
- First item
- Second item
- Third item
- Fourth item

* First item
* Second item
* Third item
* Fourth item

 + First item
 * Second item
 - Third item
 + Fourth item

## 9.4. Nesting List Items
- First item
- Second item
- Third item
    - Indented item
    - Indented item
- Fourth item

## 9.5. Code
At the command prompt, type `nano`.

``Use `code` in your Markdown file.``

#### 9.5.1. Heading level 4

##### 9.5.1.1. Heading level 5

###### 9.5.1.1.1. Heading level 6