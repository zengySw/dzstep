const create_gallery_item = ({ url, title, author }) => {
  const item = document.createElement("div");
  item.className = "gallery-item";

  const img = document.createElement("img");
  img.src = url;
  img.alt = title;

  const info = document.createElement("div");
  info.className = "gallery-item-info";

  const p_title = document.createElement("p");
  p_title.className = "gallery-item-title";
  p_title.textContent = title;

  const p_author = document.createElement("p");
  p_author.className = "gallery-item-author";
  p_author.textContent = "@ " + author;

  info.append(p_title, p_author);
  item.append(img, info);
  return item;
};

export default create_gallery_item;