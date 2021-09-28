CSS

- determines style of the web page
- exploits the DOM structure of the page!
	- if you move the styling to a parent tag, everything inside will 
	use the same style

- Instead of repeating the style for each element you want, can use style tag in the head

- But what if you have multiple html files???

- div = "division" of the pages- a section. Let's us divide page into sub-sections

- what if we only want to style specific instances of an element?
- use id's! in tags to uniquely identify each element

- Then use a #id in the css to only style elements with that id

- But we dont want to end up using too many ids in the css :(
what if we want to only style elements without an id

- instead of id, use class! Then the css can apply to all elements with the same class tag

CSS Specificity
- What if we want to style a particular element a certain way, but 
we have already styled all elements of that type?

Order of preference
- inline
- id
- class
- type
(makes sense if you think of the tree-like dom structure)

**see CSS selectors**
- e.g. can specify style to all descendents of a particular element!



Responsive:
- can use CSS to change color as you hover!
- Should use the meta viewport thing everywhere!

**Media Queries**
- Flexbox: when you want to wrap around as screen size grows/shrinks
- can create grid elements that can resize dynamically

SaSS
- Allows us to use variables in CSS!
- So prevent rewriting the same thing in different style parts