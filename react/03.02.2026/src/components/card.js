const styles = {
    card: {
        width: "240px",
        background: "#fff",
        padding: "8px",
        boxShadow: "0 2px 8px rgba(0,0,0,.08)",
        display: "flex",
        flexDirection: "column",
        position: "relative",
        transition: "box-shadow .2s ease, transform .2s ease"
    },

    like: {
        display: "flex",
        flexDirection: "row",
        justifyContent: "center",
        alignItems: "center",
        width: "32px",
        height: "32px",
        marginBottom: "var(--global-spacer)",
        backgroundColor: "#ffffffb3",
        padding: "0",
        border: "none",
        borderRadius: "var(--global-spacer)",
        cursor: "pointer",
        color: "var(--global-yellow)",
        position: "absolute",
        top: "0",
        right: "0",
        zIndex: "3",
        fontSize: "28px"
    },

    imageWrap: {
        width: "100%",
        height: "180px",
        display: "flex",
        alignItems: "center",
        justifyContent: "center",
        marginBottom: "10px"
    },

    image: {
        maxWidth: "100%",
        maxHeight: "100%",
        objectFit: "contain"
    },

    title: {
        fontSize: "14px",
        fontWeight: "400",
        lineHeight: "1.4",
        height: "40px",
        overflow: "hidden",
        marginBottom: "8px",
        color: "var(--global-black)",
        textDecoration: "none",
        wordBreak: "break-word",
    },

    bottom: {
        marginTop: "auto",
        width: "100%",
    },

    price: {
        fontSize: "20px",
        fontWeight: "700",
        color: "var(--global-black)",
        marginBottom: "6px"
    },

    currency: {
        fontSize: "20px",
        marginLeft: "var(--global-spacer)"
    },

    flags: {
        display: "flex",
        alignItems: "center",
        justifyContent: "space-between",
        gap: "var(--global-spacer)",
        fontSize: "11px",
        color: "#00a046",
    },
    buySect: {
        display: "flex",
        justifyContent: "space-between"
    },
    cart: {
        width: "32px",
        height: "32px",
    },
    addToCart: {
        width: "32px",
        height: "32px",
        border: "none",
        background: "none"
    },
    smartBtn: {
        width: "max-content",
        height: "24px",
        border: "none",
        background: "none"
    }
};


function Card({ id, href, previewImg, name, price }) {
    return (
        <div style={styles.card} id={"card_" + id}>
            <button style={styles.like}>♡</button>

            <a href={href} style={styles.imageWrap}>
                <img
                    src={previewImg || "./images/noneImg.svg"}
                    alt={name}
                    style={styles.image}
                />
            </a>

            <a href={href} style={styles.title}>{name}</a>

            <section style={styles.bottom}>
                <div style={styles.buySect}>
                    <div style={styles.price}>
                        {price}
                        <span style={styles.currency}>₴</span>
                    </div>
                    <button style={styles.addToCart}>
                        <svg style={styles.cart} width="800px" height="800px" viewBox="-2.4 -2.4 28.80 28.80" xmlns="http://www.w3.org/2000/svg" fill="none">

                            <g id="SVGRepo_bgCarrier" stroke-width="0" />

                            <g id="SVGRepo_tracerCarrier" stroke-linecap="round" stroke-linejoin="round" />

                            <g id="SVGRepo_iconCarrier"> <circle cx="7.5" cy="18.5" r="1.5" fill="#00a046" /> <circle cx="16.5" cy="18.5" r="1.5" fill="#00a046" /> <path stroke="#00a046" stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M3 5h2l.6 3m0 0L7 15h10l2-7H5.6z" /> </g>

                        </svg>
                    </button>
                </div>

                <div style={styles.flags}>
                    <span>Безкоштовна<br></br> доставка</span>
                    <button style={styles.smartBtn}>
                        <img style={{ width: "auto", height: "100%" }} src="./images/smart_promo.png" alt="smart promo" height="16" />
                    </button>
                </div>
            </section>
        </div>
    );
}

export default Card;